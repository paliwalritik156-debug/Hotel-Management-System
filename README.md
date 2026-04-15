# 🏨 Grand Azure — Hotel Management System
## Built with C++ & Qt 5/6 (Desktop GUI Application)

---

## 📋 Features

| Module         | Features |
|----------------|----------|
| **Dashboard**  | Live stats (available rooms, occupancy, guests, revenue), room grid overview, recent reservations |
| **Rooms**      | All 25 rooms across 4 floors, filter by type/status, room details popup |
| **Guests**     | Register guests, search by name/phone, view all records |
| **Reservations** | New booking with date picker, auto price calculation, check-out flow |
| **Billing**    | Record payments, view balance per booking |
| **Reports**    | Occupancy rate, revenue summary, room type breakdown |

---

## 🏗️ Room Types & Pricing

| Type          | Rooms     | Price/Night |
|---------------|-----------|-------------|
| Standard      | 101–110   | ₹2,500      |
| Deluxe        | 201–208   | ₹5,000      |
| Suite         | 301–305   | ₹10,000     |
| Presidential  | 401–402   | ₹25,000     |

---

## 🛠️ How to Build & Run

### Prerequisites
- **Qt 5.12+** or **Qt 6.x**
- **Qt Creator** (recommended) OR qmake/cmake via terminal
- C++17 compiler (MSVC, GCC, or Clang)

---

### Option 1: Qt Creator (Easiest)

1. Open **Qt Creator**
2. Go to **File → Open File or Project**
3. Select `HotelManagement.pro`
4. Click **Configure Project**
5. Press **Ctrl+R** (Run) or click the green ▶ button

---

### Option 2: Terminal (Linux/macOS)

```bash
cd hotel_mgmt
qmake HotelManagement.pro
make -j4
./HotelManagement
```

### Option 3: Terminal (Windows with Qt installed)

```cmd
cd hotel_mgmt
qmake HotelManagement.pro
nmake          # (MSVC) or mingw32-make (MinGW)
HotelManagement.exe
```

---

## 📁 Project Structure

```
hotel_mgmt/
├── main.cpp          → App entry point, global stylesheet
├── models.h          → Room, Guest, Booking structs + HotelData
├── mainwindow.h      → UI component declarations, style helpers
├── mainwindow.cpp    → Full UI implementation, all logic
└── HotelManagement.pro → Qt project file
```

---

## 💡 Notes
- Data is **in-memory** (resets on restart). To persist data, add file I/O or SQLite (`QT += sql`).
- The system pre-loads **25 rooms** on startup automatically.
- All pricing is in **Indian Rupees (₹)**.
