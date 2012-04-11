/*
 * Copyright 2009 Haiku Inc. All rights reserved.
 * Distributed under the terms of the MIT License.
 *
 * Authors:
 *		Artur Wyszynski <harakash@gmail.com>
 */


#include "OpenGLWindow.h"

#include <Application.h>
#include <Catalog.h>
#include <GroupLayout.h>
#include "OpenGLView.h"


OpenGLWindow::OpenGLWindow()
	:
	BWindow(BRect(50, 50, 450 + 64, 400),
		B_TRANSLATE_SYSTEM_NAME("3D Rendering"), B_TITLED_WINDOW,
		B_NOT_RESIZABLE | B_ASYNCHRONOUS_CONTROLS | B_NOT_ZOOMABLE
		| B_AUTO_UPDATE_SIZE_LIMITS)
{
	SetLayout(new BGroupLayout(B_VERTICAL));
	fView = new OpenGLView();
	GetLayout()->AddView(fView);
	CenterOnScreen();
}


OpenGLWindow::~OpenGLWindow()
{
}


bool
OpenGLWindow::QuitRequested()
{
	be_app->PostMessage(B_QUIT_REQUESTED);
	return true;
}


void
OpenGLWindow::MessageReceived(BMessage* message)
{
	switch (message->what) {
		default:
			BWindow::MessageReceived(message);
	}
}