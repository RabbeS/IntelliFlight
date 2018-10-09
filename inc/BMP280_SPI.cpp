#include "BMP280_SPI.h"

void setMode(enum mode select) {
    switch (select) {
        case sleep:
            break;
        case forced:
            break;
        case normal:
            break;
    }
}

void setOsrs_t(enum osrs_t select) {

}

void setPsrs_t(enum psrs_t select) {

}

void setStatus(enum status select) {

}

void sett_sb(enum t_sb select) {

}

void setFilter(enum filter select) {

}

void setSpi3w(enum spi3w_en select) {

}

void useCase(enum useCase select) {
    switch (select) {
        case handheld_device_low_power:
            break;
        case handheld_device_dynamic:
            break;
        case weather_monitoring:
            break;
        case elev_floor_change_detec:
            break;
        case drop_detec:
            break;
        case indoor_nav:
            break;
    }
}