/****************************************************************************
**
** This file is part of the LibreCAD project, a 2D CAD program
**
** Copyright (C) 2010 R. van Twisk (librecad@rvt.dds.nl)
** Copyright (C) 2001-2003 RibbonSoft. All rights reserved.
**
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software 
** Foundation and appearing in the file gpl-2.0.txt included in the
** packaging of this file.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
** 
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
**
** This copyright notice MUST APPEAR in all copies of the script!  
**
**********************************************************************/

#ifndef RS_ACTIONMODIFYROUND_H
#define RS_ACTIONMODIFYROUND_H

#include "rs_previewactioninterface.h"

struct RS_RoundData;

/**
 * This action class can handle user events to round corners.
 *
 * @author Andrew Mustun
 */
class RS_ActionModifyRound : public RS_PreviewActionInterface {
	Q_OBJECT
	/**
  * Action States.
  */
	enum Status {
		SetEntity1,   /**< Choosing the 1st entity. */
		SetEntity2,   /**< Choosing the 2nd entity. */
		SetRadius,   /**< Setting radius in command line. */
		SetTrim    /**< Setting trim flag in command line. */
	};

public:
	RS_ActionModifyRound(RS_EntityContainer& container,
						 RS_GraphicView& graphicView);
	~RS_ActionModifyRound() override;
	
	void init(int status=0) override;
	void trigger() override;

	void mouseMoveEvent(QMouseEvent* e) override;
	void mouseReleaseEvent(QMouseEvent* e) override;
	
	void commandEvent(RS_CommandEvent* e) override;
	QStringList getAvailableCommands() override;
	
	void hideOptions() override;
	void showOptions() override;
	
	void updateMouseButtonHints() override;
	void updateMouseCursor() override;
	
	void setRadius(double r);

	double getRadius() const;

	void setTrim(bool t);

	bool isTrimOn() const;

private:

    bool removeOldFillet(RS_Entity* e, const bool& isPolyline);

	//RS_Vector coord;
    RS_Entity* entity1 = nullptr;
    RS_Entity* entity2 = nullptr;
	struct Points;
	std::unique_ptr<Points> pPoints;
	/** Last status before entering angle. */
    Status lastStatus = SetEntity1;
};

#endif
