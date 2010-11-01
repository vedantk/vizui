/*
 * viz3d.cxx
 * Copyright (c) 2009 Vedant Kumar <vminch@gmail.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include "vtkRenderer.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkWindowToImageFilter.h"
#include "vtkBMPWriter.h"
#include "vtkRenderWindow.h"
#include "vtkPNMReader.h"
#include "vtkProperty.h"
#include "vtkPolyDataMapper.h"
#include "vtkMarchingCubes.h"
#include "vtkDecimatePro.h"
#include "vtkPolyDataNormals.h"
#include "vtkWindowedSincPolyDataFilter.h"
#include "vtkDataSetMapper.h"
#include "vtkActor.h"
#include "vtkDataSetMapper.h"
#include "vtkTubeFilter.h"
#include "vtkCleanPolyData.h"
#include "vtkAxes.h"

const int img_side_len = 512;
float dsx=2, dsy=2, dsz=2;
const int marching_cubes = 220;
const float deci_reduction = 0.5;
const int tube_filt_sides = 5;

int main (int argc, char** argv) {
	if (argc < 3) {
		cout << "./viz3d fprefix #imgs\n";
		return EXIT_FAILURE;
	}
	
	if (argc == 6) {
		dsx = atof(argv[3]);
		dsy = atof(argv[4]);
		dsz = atof(argv[5]);
	}
    
	vtkRenderer* ren1 = vtkRenderer::New();
	vtkRenderWindow* renWin = vtkRenderWindow::New();
	vtkRenderWindowInteractor* iren = vtkRenderWindowInteractor::New();

	const char* fprefix = argv[1];
	int num_imgs = atoi(argv[2]);
    
	vtkPNMReader* vpr = vtkPNMReader::New();
	vpr->SetDataExtent(0, img_side_len-1, 0, img_side_len-1, 1, num_imgs);
	vpr->SetDataSpacing(dsx, dsy, dsz);
	vpr->SetFilePrefix(fprefix);
	vpr->SetFilePattern("%s%.3d.pgm");
  
	vtkMarchingCubes* isoSurface = vtkMarchingCubes::New();
	isoSurface->SetInputConnection(vpr->GetOutputPort());
	isoSurface->SetValue(1, marching_cubes);

	vtkCleanPolyData* cleaner = vtkCleanPolyData::New();
	cleaner->SetInputConnection(isoSurface->GetOutputPort());

	vtkDecimatePro* deci = vtkDecimatePro::New();
	deci->SetInputConnection(cleaner->GetOutputPort());
	deci->SetTargetReduction(deci_reduction);

	vtkWindowedSincPolyDataFilter* smooth = vtkWindowedSincPolyDataFilter::New();
    smooth->SetInputConnection(deci->GetOutputPort());
    smooth->SetNumberOfIterations(10);
    smooth->BoundarySmoothingOn();
    smooth->SetFeatureAngle(120);
    smooth->SetEdgeAngle(90);
    smooth->SetPassBand(0.01);
    
    vtkPolyDataNormals* normals = vtkPolyDataNormals::New();
    normals->SetInputConnection(smooth->GetOutputPort());
    normals->SetFeatureAngle(60.0);

    vtkPolyDataMapper* SolidMapper = vtkPolyDataMapper::New();
	SolidMapper->SetInputConnection(normals->GetOutputPort());
	SolidMapper->ScalarVisibilityOff(); 

    vtkActor* SolidActor = vtkActor::New();
    SolidActor->SetMapper(SolidMapper);
    SolidActor->GetProperty()->SetOpacity(1);

	vtkAxes* axes = vtkAxes::New();
    axes->SetScaleFactor(5);
	vtkTubeFilter* axisTube = vtkTubeFilter::New();
    axisTube->SetInputConnection(axes->GetOutputPort());
    axisTube->SetRadius(0.2);
    axisTube->SetNumberOfSides(tube_filt_sides);

	vtkPolyDataMapper* AxesMapper = vtkPolyDataMapper::New();
    AxesMapper->SetInputConnection(axisTube->GetOutputPort());
    
    SolidActor->GetProperty()->SetColor(174/255.0, 0/255.0, 0/255.0);
    ren1->AddActor(SolidActor);
    ren1->SetBackground(1, 1, 1);
    renWin->AddRenderer(ren1);
    renWin->SetInteractor(iren);
    renWin->SetSize(800, 600);
    
    iren->Initialize();
    iren->Start();
    
    vtkWindowToImageFilter* wtf = vtkWindowToImageFilter::New();
    wtf->SetInput(renWin);
    vtkBMPWriter* writer = vtkBMPWriter::New();
    writer->SetInput(wtf->GetOutput());
    
    char nbuf[512];
    sprintf(nbuf, "%sscreenshot.bmp", argv[1]);
    writer->SetFileName(nbuf);
    writer->Write();
    cout << "Screenshot saved to: " << nbuf << endl;

	return 0;
}
