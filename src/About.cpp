#include "About.h"

About::About(wxWindow *wnd) : wxDialog(wnd, wxID_ANY, _("About"), wxDefaultPosition, wxDefaultSize, 0){
	// Window background
	this->SetBackgroundColour(wxColor(225,225,225));
	// Create subwindows
	this->CreateElements();
	// Set layout
	this->PlaceElements();
}

void About::CreateElements(){
	// Logo
	wxBitmap bmp = wxBITMAP(logo_bmp);
	this->pic = new wxStaticBitmap(this, wxID_ANY, bmp);
	// Description
	this->text = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(bmp.GetWidth(),230),
						wxTE_NO_VSCROLL | wxTE_LEFT | wxTE_BESTWRAP | wxTE_READONLY | wxTE_MULTILINE | wxTE_RICH | wxTE_RICH2 | wxTE_AUTO_URL | wxSUNKEN_BORDER);
	wxTextAttr attrib;
	attrib.SetFontSize(10);
	attrib.SetFontWeight(wxFONTWEIGHT_BOLD);
	attrib.SetFontUnderlined(true);
	this->text->SetDefaultStyle(attrib);
	this->text->AppendText(wxT("NyuFX v1.6.0\n"));
	attrib.SetFontUnderlined(false);
	this->text->SetDefaultStyle(attrib);
	this->text->AppendText(_("Karaoke effect creation with pixel & vector utilities.") + wxT("\n\n"));
	this->text->AppendText(_("Programmer:") + wxT("\n"));
	attrib.SetFontWeight(wxFONTWEIGHT_NORMAL);
	this->text->SetDefaultStyle(attrib);
	this->text->AppendText(wxT("  Youka\n"));
	attrib.SetFontWeight(wxFONTWEIGHT_BOLD);
	this->text->SetDefaultStyle(attrib);
	this->text->AppendText(_("Thanks to:") + wxT("\n"));
	attrib.SetFontWeight(wxFONTWEIGHT_NORMAL);
	this->text->SetDefaultStyle(attrib);
	this->text->AppendText(wxT("  wxWidgets - Copyright \u00A9 Robert Roebling & Co.\n"));
	this->text->AppendText(wxT("  Scintilla - Copyright \u00A9 Neil Hodgson\n"));
	this->text->AppendText(wxT("  Lua - Copyright \u00A9 PUC-Rio.\n"));
	attrib.SetFontWeight(wxFONTWEIGHT_BOLD);
	this->text->SetDefaultStyle(attrib);
	this->text->AppendText(_("Website:") + wxT("\n"));
	attrib.SetFontWeight(wxFONTWEIGHT_NORMAL);
	this->text->SetDefaultStyle(attrib);
	this->text->AppendText(wxT("  http://forum.youka.de\n"));
	attrib.SetFontWeight(wxFONTWEIGHT_BOLD);
	this->text->SetDefaultStyle(attrib);
	this->text->AppendText(wxT("Copyright:\n"));
	attrib.SetFontWeight(wxFONTWEIGHT_NORMAL);
	this->text->SetDefaultStyle(attrib);
	this->text->AppendText(wxT("  www.gnu.org/copyleft/lesser.html"));
	this->text->SetInsertionPoint(0);
	// Button
	this->ok = new wxButton(this, wxID_OK, _("Close"));
	this->ok->SetCursor(wxCURSOR_HAND);
}

void About::PlaceElements(){
	this->v_box = new wxBoxSizer(wxVERTICAL);

	this->v_box->Add(this->pic, 0, wxALL, 5);
	this->v_box->Add(this->text, 0, wxLEFT | wxRIGHT, 5);
	this->v_box->Add(this->ok, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	// Place everything
	this->SetSizer(this->v_box);
	this->v_box->SetSizeHints(this);

	// Focus window
	this->Center();
	this->ok->SetFocus();
}

// Bind event IDs to event handlers
BEGIN_EVENT_TABLE(About, wxDialog)
	EVT_TEXT_URL(wxID_ANY, About::OnURLClick)
END_EVENT_TABLE()

// Define event handlers
void About::OnURLClick(wxTextUrlEvent &url){
	if(url.GetMouseEvent().LeftDown())
		wxLaunchDefaultBrowser(this->text->GetRange(url.GetURLStart(), url.GetURLEnd()));
}