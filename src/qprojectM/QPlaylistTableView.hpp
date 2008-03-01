/***************************************************************************
 *   Copyright (C) 2007 by carm   *
 *   carm@localhost   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#ifndef QPLAYLIST_TABLEVIEW_HPP
#define QPLAYLIST_TABLEVIEW_HPP

#include <QTableView>
#include <QtDebug>
#include <QKeyEvent>
#include <QMap>
#include <QList>
class QPlaylistTableView : public QTableView
 {
     Q_OBJECT        // must include this if you use Qt signals/slots

 public:
     inline QPlaylistTableView(QWidget * parent = 0): 
		QTableView(parent) {}
 signals:
	 void resized(QResizeEvent * event);
	 void deletesRequested(const QModelIndexList & items); 
	 
 public slots:
    
	 inline void resizeEvent(QResizeEvent * event) {

		emit(resized(event));
	 }	
	 
	 
	 inline void keyReleaseEvent(QKeyEvent * event) {
		 
		switch (event->key()) {
			case Qt::Key_Delete: 
				emit(deletesRequested(selectedIndexes()));
				break;
			default:
				event->ignore();
				break;
		}
	 }
};



#endif