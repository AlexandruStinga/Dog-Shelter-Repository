cmake_minimum_required(VERSION 3.17)
project(a45_Alexandru_Stinga)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 6)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt6::Core Qt6::Gui Qt6::Widgets)
include_directories(domain)

add_executable(a45_Alexandru_Stinga
        domain/domain.cpp
        domain/domain.h
        main.cpp
        repository/repo.cpp
        repository/repo.h
        service/service.cpp
        service/service.h
        ui/ui.cpp
        ui/ui.h
        tests/tests.cpp
        tests/tests.h service/user_service.cpp service/user_service.h repository/filerepo.cpp repository/filerepo.h repository/AdoptionRepo.cpp repository/AdoptionRepo.h repository/fileAdoptionRepo.cpp repository/fileAdoptionRepo.h domain/validator.cpp domain/validator.h domain/exceptions.h repository/HTMLAdoptionRepo.cpp repository/HTMLAdoptionRepo.h repository/CSVAdoptionRepo.cpp repository/CSVAdoptionRepo.h
        ui/mainwindow.cpp
        ui/mainwindow.h
        ui/mainwindow.ui
        ui/GUI.cpp
        ui/GUI.h
        ui/AdminGUI.cpp
        ui/AdminGUI.h ui/UserGUI.cpp ui/UserGUI.h
        service/CommandController.cpp
        service/CommandController.h
        ui/Table.cpp
        ui/Table.h)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
