#pragma once
#include <QMainWindow>
#include <QStackedWidget>
#include <QLabel>
#include <QPushButton>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QComboBox>
#include <QLineEdit>
#include <QDateEdit>
#include <QSpinBox>
#include <QTextEdit>
#include <QFormLayout>
#include <QScrollArea>
#include <QDialog>
#include <QMessageBox>
#include <QHeaderView>
#include <QGridLayout>
#include <QButtonGroup>
#include <QScreen>
#include <QRegularExpression>
#include "models.h"
class SidebarButton:public QPushButton{Q_OBJECT public:SidebarButton(const QString&icon,const QString&label,QWidget*p=nullptr):QPushButton(p){setText("  "+icon+"    "+label);setCheckable(true);setFixedHeight(48);setCursor(Qt::PointingHandCursor);setStyleSheet(R"(QPushButton{background:transparent;color:rgba(255,255,255,0.5);border:none;border-left:3px solid transparent;text-align:left;padding:0 24px;font-size:13px;}QPushButton:hover{color:#E8D5A3;background:rgba(212,175,55,0.08);border-left:3px solid rgba(212,175,55,0.3);}QPushButton:checked{color:#D4AF37;background:rgba(212,175,55,0.12);border-left:3px solid #D4AF37;font-weight:600;})");}};
class StatCard:public QFrame{Q_OBJECT QLabel*valL;public:StatCard(const QString&lbl,const QString&val,const QString&color,const QString&icon,QWidget*p=nullptr):QFrame(p){setFixedHeight(110);setStyleSheet("QFrame{background:white;border-radius:16px;border:1px solid #F0EBE0;}");auto*lay=new QHBoxLayout(this);lay->setContentsMargins(20,16,20,16);lay->setSpacing(16);auto*iconW=new QLabel(icon);iconW->setFixedSize(48,48);iconW->setAlignment(Qt::AlignCenter);iconW->setStyleSheet(QString("background:%1;border-radius:24px;font-size:20px;").arg(color));lay->addWidget(iconW);auto*right=new QWidget();auto*rl=new QVBoxLayout(right);rl->setContentsMargins(0,0,0,0);rl->setSpacing(4);valL=new QLabel(val);valL->setStyleSheet("color:#1A1A2E;font-size:28px;font-weight:700;");auto*lblL=new QLabel(lbl);lblL->setStyleSheet("color:#8A97A8;font-size:11px;letter-spacing:1px;");rl->addWidget(valL);rl->addWidget(lblL);lay->addWidget(right);lay->addStretch();}void setValue(const QString&v){valL->setText(v);}};
class SectionHeader:public QWidget{Q_OBJECT public:SectionHeader(const QString&title,const QString&sub="",QWidget*p=nullptr):QWidget(p){auto*lay=new QVBoxLayout(this);lay->setContentsMargins(0,0,0,0);lay->setSpacing(3);auto*t=new QLabel(title);t->setStyleSheet("font-size:22px;font-weight:700;color:#1A1A2E;");lay->addWidget(t);if(!sub.isEmpty()){auto*s=new QLabel(sub);s->setStyleSheet("font-size:13px;color:#8A97A8;");lay->addWidget(s);}}};
inline QTableWidget*makeTable(const QStringList&h,QWidget*p=nullptr){auto*t=new QTableWidget(0,h.size(),p);t->setHorizontalHeaderLabels(h);t->setEditTriggers(QAbstractItemView::NoEditTriggers);t->setSelectionBehavior(QAbstractItemView::SelectRows);t->verticalHeader()->setVisible(false);t->horizontalHeader()->setStretchLastSection(true);t->setShowGrid(false);t->setFocusPolicy(Qt::NoFocus);t->setAlternatingRowColors(false);t->setStyleSheet(R"(QTableWidget{background:white;border-radius:12px;border:1px solid #F0EBE0;font-size:13px;color:#2D3748;}QTableWidget::item{padding:12px 16px;border-bottom:1px solid #FAF7F2;}QTableWidget::item:selected{background:#FBF5E6;color:#1A1A2E;}QHeaderView::section{background:#1A1A2E;color:#D4AF37;font-size:10px;font-weight:700;letter-spacing:2px;padding:12px 16px;border:none;})");t->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);t->verticalHeader()->setDefaultSectionSize(48);return t;}
inline QPushButton*goldBtn(const QString&t,QWidget*p=nullptr){auto*b=new QPushButton(t,p);b->setCursor(Qt::PointingHandCursor);b->setStyleSheet(R"(QPushButton{background:#D4AF37;color:#1A1A2E;border:none;border-radius:8px;padding:10px 24px;font-size:13px;font-weight:700;}QPushButton:hover{background:#E8C84A;}QPushButton:pressed{background:#B8962E;})");return b;}
inline QPushButton*outlineBtn(const QString&t,QWidget*p=nullptr){auto*b=new QPushButton(t,p);b->setCursor(Qt::PointingHandCursor);b->setStyleSheet(R"(QPushButton{background:transparent;color:#D4AF37;border:1.5px solid #D4AF37;border-radius:8px;padding:9px 20px;font-size:13px;font-weight:600;}QPushButton:hover{background:rgba(212,175,55,0.1);})");return b;}
inline QPushButton*dangerBtn(const QString&t,QWidget*p=nullptr){auto*b=new QPushButton(t,p);b->setCursor(Qt::PointingHandCursor);b->setStyleSheet(R"(QPushButton{background:#E53E3E;color:white;border:none;border-radius:8px;padding:9px 20px;font-size:13px;font-weight:600;}QPushButton:hover{background:#FC8181;})");return b;}
inline QPushButton*successBtn(const QString&t,QWidget*p=nullptr){auto*b=new QPushButton(t,p);b->setCursor(Qt::PointingHandCursor);b->setStyleSheet(R"(QPushButton{background:#38A169;color:white;border:none;border-radius:8px;padding:9px 20px;font-size:13px;font-weight:600;}QPushButton:hover{background:#48BB78;})");return b;}
inline QLineEdit*styledInput(const QString&ph="",QWidget*p=nullptr){auto*e=new QLineEdit(p);e->setPlaceholderText(ph);e->setMinimumHeight(40);e->setStyleSheet(R"(QLineEdit{background:#FAFAFA;border:1.5px solid #E8E0D0;border-radius:8px;padding:8px 14px;font-size:13px;color:#2D3748;}QLineEdit:focus{border:1.5px solid #D4AF37;background:white;})");return e;}
inline QComboBox*styledCombo(QWidget*p=nullptr){auto*c=new QComboBox(p);c->setMinimumHeight(40);c->setStyleSheet(R"(QComboBox{background:#FAFAFA;border:1.5px solid #E8E0D0;border-radius:8px;padding:8px 14px;font-size:13px;color:#2D3748;min-width:160px;}QComboBox:focus{border:1.5px solid #D4AF37;}QComboBox::drop-down{border:none;width:28px;}QComboBox QAbstractItemView{background:white;border:1.5px solid #E8E0D0;selection-background-color:#FBF5E6;selection-color:#1A1A2E;padding:4px;})");return c;}
inline QDateEdit*styledDate(QWidget*p=nullptr){auto*d=new QDateEdit(QDate::currentDate(),p);d->setCalendarPopup(true);d->setDisplayFormat("dd/MM/yyyy");d->setMinimumHeight(40);d->setStyleSheet(R"(QDateEdit{background:#FAFAFA;border:1.5px solid #E8E0D0;border-radius:8px;padding:8px 14px;font-size:13px;color:#2D3748;}QDateEdit:focus{border:1.5px solid #D4AF37;}QDateEdit::drop-down{border:none;width:28px;})");return d;}
static QWidget*pageWrap(QLayout*inner){auto*content=new QWidget();content->setStyleSheet("background:#F8F4EE;");content->setLayout(inner);auto*scroll=new QScrollArea();scroll->setWidgetResizable(true);scroll->setFrameShape(QFrame::NoFrame);scroll->setStyleSheet("background:#F8F4EE;border:none;");scroll->setWidget(content);auto*root=new QWidget();root->setStyleSheet("background:#F8F4EE;");auto*rl=new QVBoxLayout(root);rl->setContentsMargins(0,0,0,0);rl->addWidget(scroll);return root;}
class MainWindow:public QMainWindow{Q_OBJECT
HotelData hotel;QStackedWidget*stack;
SidebarButton*btnDash,*btnRooms,*btnGuests,*btnBook,*btnBill,*btnRestaurant,*btnLaundry,*btnReport;
StatCard*statAvail,*statOccupied,*statGuests,*statRevenue;
QTableWidget*roomTable,*guestTable,*bookingTable;
public:
MainWindow(QWidget*p=nullptr);~MainWindow(){}
private:
void buildUI();QWidget*buildSidebar();QWidget*buildDashboard();QWidget*buildRoomsPage();QWidget*buildGuestsPage();QWidget*buildBookingPage();QWidget*buildBillingPage();QWidget*buildRestaurantPage();QWidget*buildLaundryPage();QWidget*buildReportPage();
void refreshRoomTable();void refreshGuestTable();void refreshBookingTable();void refreshRestaurantTable();void refreshLaundryTable();void refreshBillingTable();void refreshDashboard();
void showAddGuestDialog();void showAddBookingDialog();void showCheckoutDialog();void showPaymentDialog(int);void showRoomDetailDialog(int);void showRestaurantOrderDialog();void showLaundryOrderDialog();
void switchPage(int);
QString formatCurrency(double v){return QString("Rs.%1").arg((long long)v);}
};
