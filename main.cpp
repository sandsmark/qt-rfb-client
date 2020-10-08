/*
 * Copyright (C) 2013 Azril Azam
 * <azrilazam@gmail.com>
 *
 * Desc
 *
 * This file is a part of the 100% Qt5 VNC RFB-CLIENT implementation without
 * using any 3rd party rfb library
 *
 * main.cpp
 *
 *
 * Qt5 RFB-CLIENT is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * Qt5 RFB-CLIENT is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Qt HTML platform plugin. If not, see
 * <http://www.gnu.org/licenses/>.
 */

#include <QApplication>
#include "vncclientwidget2cls.h"
#include "rfbclientwidgetcls.h"
#include "vncclientwidget2cls.h"

#ifdef RM_DEVICE
#include <epframebuffer.h>
#endif

int main(int argc, char *argv[])
{
#ifdef RM_DEVICE
    qputenv("QT_QPA_PLATFORM", "epaper:enable_fonts");
#endif

    QApplication a(argc, argv);
    vncclientwidget2cls vnc;
#ifdef RM_DEVICE
    EPFrameBuffer::clearScreen();
    vnc.connectVNCTCP("10.11.99.2", 5900); // connect via TCP
#else
    vnc.connectVNCTCP("localhost", 3389); // connect via TCP
#endif
    //vnc.connectVNCIPC("/var/nemd3/nemd3vnc"); connect via UNIX socket
    vnc.show();
    return a.exec();
}
