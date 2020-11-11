///\file CGUIexScrollWindow.cpp
 /// Containing the CGUIexScrollWindow class

 ///\class CGUIexScrollWindow
 /// Helper class for a window with scroll bar. Based on http://www.irrforge.org/index.php/CGUITextBox .
 /// Kudos to MasterD.
 /// Irrlicht extension class. Remember to use "new" and "delete" when creating or releasing an element of
 /// this type. No add, no drop, no remove. 12/2005 Michael Koch

 #include "CGUIexScrollWindow.h"

 namespace irr
 {
 namespace gui
 {

 /// Constructor, setting itself as a child to the gui root element
 // ------------------------------------------------------------------------------------------------
 CGUIexScrollWindow::CGUIexScrollWindow(irr::gui::IGUIEnvironment *pGuiEnv,
 irr::gui::IGUIFont *pFont,
 irr::core::rect<irr::s32> rec)
 : IGUIElement(irr::gui::EGUIET_ELEMENT, pGuiEnv,
 pGuiEnv->getRootGUIElement(), -1, rec)
 // ------------------------------------------------------------------------------------------------
 {
 m_pFont = pFont;

 m_pScrollbar = NULL;
 m_pDummyText = NULL;
 m_pStaticText = NULL;

 Init(); // Called once on creation
 }

 /// Initializing internal elements.
 // ------------------------------------------------------------------------------------------------
void CGUIexScrollWindow::Init(void)
 // ------------------------------------------------------------------------------------------------
{
m_pDummyText = Environment->addStaticText(L"",irr::core::rect<irr::s32>(0, 0,RelativeRect.getWidth(),RelativeRect.getHeight()),true, true, this, -1 , true);
m_pStaticText = Environment->addStaticText(L"",irr::core::rect<irr::s32>(5, 5,RelativeRect.getWidth()-15-5,RelativeRect.getHeight()-5),false, true, this);
m_pScrollbar = Environment->addScrollBar(false,irr::core::rect<irr::s32>(RelativeRect.getWidth()-15,0,RelativeRect.getWidth(),RelativeRect.getHeight()),this);
m_pStaticText->setOverrideFont(m_pFont);

//setText(Text.c_str());

}

 /// Destructor. The object is removing itself from the parent (the gui root element, that is)
 // ------------------------------------------------------------------------------------------------
 CGUIexScrollWindow::~CGUIexScrollWindow()
 // ------------------------------------------------------------------------------------------------
 {
 Parent->removeChild(this);
 }

 /// Called if an event happened. Filter for our scrollbar
 // ------------------------------------------------------------------------------------------------
 bool CGUIexScrollWindow::OnEvent(irr::SEvent &event)
 // ------------------------------------------------------------------------------------------------
 {

if (Parent) Parent->OnEvent(event);
else 
 if (event.EventType == EET_GUI_EVENT && event.GUIEvent.EventType == EGET_SCROLL_BAR_CHANGED)
 {
	 IGUIScrollBar *bar = static_cast <irr::gui::IGUIScrollBar*> (event.GUIEvent.Caller);
	 if (bar == m_pScrollbar)
	 {
		 irr::s32 line = m_pScrollbar->getPos();
		 setVisibleText(line); // Line is in pixels here
	 }
 } 

 return true;
 }

 /// Set new text to the window and calculate new scrollbar range (in pixels)
 // ------------------------------------------------------------------------------------------------
 void CGUIexScrollWindow::setText(const wchar_t* pText)
 // ------------------------------------------------------------------------------------------------
 {
 m_pStaticText->setText(pText);

 m_pScrollbar->setMax(m_pStaticText->getTextHeight() - m_pScrollbar->getRelativePosition().getHeight());

 m_pScrollbar->setPos(0);
setVisibleText(0);
 }

 /// Called when scrolling applies
 // ------------------------------------------------------------------------------------------------
 void CGUIexScrollWindow::setVisibleText(irr::s32 iStartLine)
 // ------------------------------------------------------------------------------------------------
 {
 // startLine is given in pixels

 irr::core::rect<irr::s32> dim1 = m_pStaticText->getRelativePosition();
 irr::core::rect<irr::s32> dim2(dim1.UpperLeftCorner.X,- iStartLine,dim1.LowerRightCorner.X,m_pStaticText->getTextHeight() - iStartLine);

 m_pStaticText->setRelativePosition(dim2);
 }

 } // namespace gui
 } // namespace irr
 