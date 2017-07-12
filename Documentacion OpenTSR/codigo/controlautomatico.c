int  MainWindow::accion_SVR(std::vector<char> &v){


    // 100 km/h
    if ((std::find(v.begin(), v.end(),'1')!= v.end()) &&
        (std::find(v.begin(), v.end(),'0') != v.end())){

        // Se elimina un '0'.
        std::vector<char>::iterator pos = std::find(v.begin(), v.end(),'0');
        v.erase(pos);

        // Si existe otro cero...
        if(std::find(v.begin(), v.end(),'0')!= v.end()){

            // 100 km/h
            if(conectado && ui->checkBox_2->isChecked() && ultima_senial != 10){
                ultima_senial = 10;
                robot.move(STOP);
                this->velocidad = 100;
                robot.drive(this->velocidad,this->velocidad);
            }
            //Mostrar señal detectada
            mostrar_senial_detectada("10.jpg");

            return 0;
        }
    }


    // 20 km/h
    if ((std::find(v.begin(), v.end(),'2') != v.end()) && 
        (std::find(v.begin(), v.end(),'0') != v.end())){

        if(conectado && ui->checkBox_2->isChecked() && ultima_senial != 2){
            ultima_senial = 2;
            robot.move(STOP);
            this->velocidad = 20;
            robot.drive(this->velocidad,this->velocidad);
        }
        //Mostrar señal detectada
        mostrar_senial_detectada("2.jpg");
        return 0;
    }

    // 30 km/h
    if ((std::find(v.begin(), v.end(),'3') != v.end()) && 
       (std::find(v.begin(), v.end(),'0') != v.end())){

        if(conectado && ui->checkBox_2->isChecked() && ultima_senial != 3){
            ultima_senial = 3;

            robot.move(STOP);
            this->velocidad = 30;
            robot.drive(this->velocidad,this->velocidad);
        }
        //Mostrar señal detectada
        mostrar_senial_detectada("3.jpg");
        return 0;
    }

    // 40 km/h
    if ((std::find(v.begin(), v.end(),'4') != v.end()) &&
        (std::find(v.begin(), v.end(),'0') != v.end())){

        if(conectado && ui->checkBox_2->isChecked() && ultima_senial != 4){
            ultima_senial = 4;
            robot.move(STOP);
            this->velocidad = 40;
            robot.drive(this->velocidad,this->velocidad);
        }
        //Mostrar señal detectada
        mostrar_senial_detectada("4.jpg");
        return 0;
    }

    // 50 km/h
    if ((std::find(v.begin(), v.end(),'5')!=v.end()) &&
        (std::find(v.begin(), v.end(),'0') != v.end())){

        if(conectado && ui->checkBox_2->isChecked() && ultima_senial != 5){
            ultima_senial = 5;
            robot.move(STOP);
            this->velocidad = 50;
            robot.drive(this->velocidad,this->velocidad);
        }

        //Mostrar señal detectada
        mostrar_senial_detectada("5.jpg");
        return 0;
    }

    // 60 km/h
    if ((std::find(v.begin(), v.end(),'6')!= v.end()) && 
        (std::find(v.begin(), v.end(),'0') != v.end())){


        if(conectado && ui->checkBox_2->isChecked() && ultima_senial != 6){
            ultima_senial = 6;
            robot.move(STOP);
            this->velocidad = 60;
            robot.drive(this->velocidad,this->velocidad);
        }
        //Mostrar señal detectada
        mostrar_senial_detectada("6.jpg");
        return 0;
    }

    // 70 km/h
    if ((std::find(v.begin(), v.end(),'7')!= v.end()) &&
        (std::find(v.begin(), v.end(),'0') != v.end())){

        if(conectado && ui->checkBox_2->isChecked() && ultima_senial != 7){
            ultima_senial = 7;
            robot.move(STOP);
            this->velocidad = 70;
            robot.drive(this->velocidad,this->velocidad);
        }

        mostrar_senial_detectada("7.jpg");
        return 0;
    }

    // 80 km/h
    if ((std::find(v.begin(), v.end(),'8')!= v.end()) && 
        (std::find(v.begin(), v.end(),'0') != v.end())){

        if(conectado && ui->checkBox_2->isChecked() && ultima_senial != 8){
            ultima_senial = 8;
            robot.move(STOP);
            this->velocidad = 80;
            robot.drive(this->velocidad,this->velocidad);
        }

        //Mostrar señal detectada
        mostrar_senial_detectada("8.jpg");
        return 0;
    }

    // 90 km/h
    if ((std::find(v.begin(), v.end(),'9')!= v.end()) && 
        (std::find(v.begin(), v.end(),'0') != v.end())){

        if(conectado && ui->checkBox_2->isChecked() && ultima_senial != 9){
            ultima_senial = 9;

            robot.move(STOP);
            this->velocidad = 90;
            robot.drive(this->velocidad,this->velocidad);
        }


        //Mostrar señal detectada
        mostrar_senial_detectada("9.jpg");
        return 0;
    }


    // Stop
    if ((std::find(v.begin(), v.end(),'t')!= v.end()) && 
        (std::find(v.begin(), v.end(),'p') != v.end())){

        if(conectado && ui->checkBox_2->isChecked() && ultima_senial != 1){
            ultima_senial = 1;
            robot.move(STOP);
            robot.drive(this->velocidad,this->velocidad);
        }


        //Mostrar señal detectada
        mostrar_senial_detectada("1.jpg");
        return 0;
    }


    // Derecha
    if (std::find(v.begin(), v.end(),'d')!= v.end() && v.size() == 1){

        if(conectado && ui->checkBox_2->isChecked() && ultima_senial != 12){
            ultima_senial = 12;

            robot.move(STOP);
            robot.drive(0,this->velocidad,10);
        robot.drive(this->velocidad,this->velocidad);
        }


        //Mostrar señal detectada
        mostrar_senial_detectada("12.jpg");

        return 0;
    }

    // Izquierda
    if (std::find(v.begin(), v.end(),'i')!= v.end() && v.size() == 1){

        if(conectado && ui->checkBox_2->isChecked() && ultima_senial != 13){
            ultima_senial = 13;

            robot.move(STOP);
            robot.drive(this->velocidad,0,10);
            robot.drive(this->velocidad,this->velocidad);
        }

        //Mostrar señal detectada
        mostrar_senial_detectada("13.jpg");

        return 0;

    }

    return 1;
}

