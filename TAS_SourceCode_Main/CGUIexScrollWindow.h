// CGUIexScrollWindow.h

 #ifndef ___CGUIEXSCROLLWINDOW_H
 #define ___CGUIEXSCROLLWINDOW_H

 #include <irrlicht.h>
 #include <wchar.h>

 namespace irr
 {
 namespace gui
 {

 // ------------------------------------------------------------------------------------------------
 class CGUIexScrollWindow : public irr::gui::IGUIElement
 {
 public:

 CGUIexScrollWindow(irr::gui::IGUIEnvironment *pGuiEnv,
 irr::gui::IGUIFont *pFont,
 irr::core::rect<irr::s32> rec);

 ~CGUIexScrollWindow();

 virtual bool OnEvent(irr::SEvent &event);
 virtual void setText(const wchar_t* pText);

 private:
 void setVisibleText(irr::s32 iStartLine);
 void Init(void);

 irr::gui::IGUIScrollBar * m_pScrollbar;
 irr::gui::IGUIStaticText * m_pStaticText; // keeping the text
 irr::gui::IGUIStaticText * m_pDummyText; // just for the border

 irr::gui::IGUIFont *m_pFont;
 };
 // ------------------------------------------------------------------------------------------------

 } // namespace gui
 } // namespace irr

 #endif
 