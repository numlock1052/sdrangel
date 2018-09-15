/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube    ---   Limitations and specifcities:    * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV and DATV demodulators, Channel Analyzer NG, LoRa demodulator   * The device settings and report structures contains only the sub-structure corresponding to the device type. The DeviceSettings and DeviceReport structures documented here shows all of them but only one will be or should be present at a time   * The channel settings and report structures contains only the sub-structure corresponding to the channel type. The ChannelSettings and ChannelReport structures documented here shows all of them but only one will be or should be present at a time    --- 
 *
 * OpenAPI spec version: 4.1.0
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */


#include "SWGSDRdaemonSinkSettings.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGSDRdaemonSinkSettings::SWGSDRdaemonSinkSettings(QString* json) {
    init();
    this->fromJson(*json);
}

SWGSDRdaemonSinkSettings::SWGSDRdaemonSinkSettings() {
    center_frequency = 0;
    m_center_frequency_isSet = false;
    sample_rate = 0;
    m_sample_rate_isSet = false;
    tx_delay = 0.0f;
    m_tx_delay_isSet = false;
    nb_fec_blocks = 0;
    m_nb_fec_blocks_isSet = false;
    api_address = nullptr;
    m_api_address_isSet = false;
    api_port = 0;
    m_api_port_isSet = false;
    data_address = nullptr;
    m_data_address_isSet = false;
    data_port = 0;
    m_data_port_isSet = false;
    device_index = 0;
    m_device_index_isSet = false;
    channel_index = 0;
    m_channel_index_isSet = false;
}

SWGSDRdaemonSinkSettings::~SWGSDRdaemonSinkSettings() {
    this->cleanup();
}

void
SWGSDRdaemonSinkSettings::init() {
    center_frequency = 0;
    m_center_frequency_isSet = false;
    sample_rate = 0;
    m_sample_rate_isSet = false;
    tx_delay = 0.0f;
    m_tx_delay_isSet = false;
    nb_fec_blocks = 0;
    m_nb_fec_blocks_isSet = false;
    api_address = new QString("");
    m_api_address_isSet = false;
    api_port = 0;
    m_api_port_isSet = false;
    data_address = new QString("");
    m_data_address_isSet = false;
    data_port = 0;
    m_data_port_isSet = false;
    device_index = 0;
    m_device_index_isSet = false;
    channel_index = 0;
    m_channel_index_isSet = false;
}

void
SWGSDRdaemonSinkSettings::cleanup() {




    if(api_address != nullptr) { 
        delete api_address;
    }

    if(data_address != nullptr) { 
        delete data_address;
    }



}

SWGSDRdaemonSinkSettings*
SWGSDRdaemonSinkSettings::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGSDRdaemonSinkSettings::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&center_frequency, pJson["centerFrequency"], "qint32", "");
    
    ::SWGSDRangel::setValue(&sample_rate, pJson["sampleRate"], "qint32", "");
    
    ::SWGSDRangel::setValue(&tx_delay, pJson["txDelay"], "float", "");
    
    ::SWGSDRangel::setValue(&nb_fec_blocks, pJson["nbFECBlocks"], "qint32", "");
    
    ::SWGSDRangel::setValue(&api_address, pJson["apiAddress"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&api_port, pJson["apiPort"], "qint32", "");
    
    ::SWGSDRangel::setValue(&data_address, pJson["dataAddress"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&data_port, pJson["dataPort"], "qint32", "");
    
    ::SWGSDRangel::setValue(&device_index, pJson["deviceIndex"], "qint32", "");
    
    ::SWGSDRangel::setValue(&channel_index, pJson["channelIndex"], "qint32", "");
    
}

QString
SWGSDRdaemonSinkSettings::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGSDRdaemonSinkSettings::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_center_frequency_isSet){
        obj->insert("centerFrequency", QJsonValue(center_frequency));
    }
    if(m_sample_rate_isSet){
        obj->insert("sampleRate", QJsonValue(sample_rate));
    }
    if(m_tx_delay_isSet){
        obj->insert("txDelay", QJsonValue(tx_delay));
    }
    if(m_nb_fec_blocks_isSet){
        obj->insert("nbFECBlocks", QJsonValue(nb_fec_blocks));
    }
    if(api_address != nullptr && *api_address != QString("")){
        toJsonValue(QString("apiAddress"), api_address, obj, QString("QString"));
    }
    if(m_api_port_isSet){
        obj->insert("apiPort", QJsonValue(api_port));
    }
    if(data_address != nullptr && *data_address != QString("")){
        toJsonValue(QString("dataAddress"), data_address, obj, QString("QString"));
    }
    if(m_data_port_isSet){
        obj->insert("dataPort", QJsonValue(data_port));
    }
    if(m_device_index_isSet){
        obj->insert("deviceIndex", QJsonValue(device_index));
    }
    if(m_channel_index_isSet){
        obj->insert("channelIndex", QJsonValue(channel_index));
    }

    return obj;
}

qint32
SWGSDRdaemonSinkSettings::getCenterFrequency() {
    return center_frequency;
}
void
SWGSDRdaemonSinkSettings::setCenterFrequency(qint32 center_frequency) {
    this->center_frequency = center_frequency;
    this->m_center_frequency_isSet = true;
}

qint32
SWGSDRdaemonSinkSettings::getSampleRate() {
    return sample_rate;
}
void
SWGSDRdaemonSinkSettings::setSampleRate(qint32 sample_rate) {
    this->sample_rate = sample_rate;
    this->m_sample_rate_isSet = true;
}

float
SWGSDRdaemonSinkSettings::getTxDelay() {
    return tx_delay;
}
void
SWGSDRdaemonSinkSettings::setTxDelay(float tx_delay) {
    this->tx_delay = tx_delay;
    this->m_tx_delay_isSet = true;
}

qint32
SWGSDRdaemonSinkSettings::getNbFecBlocks() {
    return nb_fec_blocks;
}
void
SWGSDRdaemonSinkSettings::setNbFecBlocks(qint32 nb_fec_blocks) {
    this->nb_fec_blocks = nb_fec_blocks;
    this->m_nb_fec_blocks_isSet = true;
}

QString*
SWGSDRdaemonSinkSettings::getApiAddress() {
    return api_address;
}
void
SWGSDRdaemonSinkSettings::setApiAddress(QString* api_address) {
    this->api_address = api_address;
    this->m_api_address_isSet = true;
}

qint32
SWGSDRdaemonSinkSettings::getApiPort() {
    return api_port;
}
void
SWGSDRdaemonSinkSettings::setApiPort(qint32 api_port) {
    this->api_port = api_port;
    this->m_api_port_isSet = true;
}

QString*
SWGSDRdaemonSinkSettings::getDataAddress() {
    return data_address;
}
void
SWGSDRdaemonSinkSettings::setDataAddress(QString* data_address) {
    this->data_address = data_address;
    this->m_data_address_isSet = true;
}

qint32
SWGSDRdaemonSinkSettings::getDataPort() {
    return data_port;
}
void
SWGSDRdaemonSinkSettings::setDataPort(qint32 data_port) {
    this->data_port = data_port;
    this->m_data_port_isSet = true;
}

qint32
SWGSDRdaemonSinkSettings::getDeviceIndex() {
    return device_index;
}
void
SWGSDRdaemonSinkSettings::setDeviceIndex(qint32 device_index) {
    this->device_index = device_index;
    this->m_device_index_isSet = true;
}

qint32
SWGSDRdaemonSinkSettings::getChannelIndex() {
    return channel_index;
}
void
SWGSDRdaemonSinkSettings::setChannelIndex(qint32 channel_index) {
    this->channel_index = channel_index;
    this->m_channel_index_isSet = true;
}


bool
SWGSDRdaemonSinkSettings::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_center_frequency_isSet){ isObjectUpdated = true; break;}
        if(m_sample_rate_isSet){ isObjectUpdated = true; break;}
        if(m_tx_delay_isSet){ isObjectUpdated = true; break;}
        if(m_nb_fec_blocks_isSet){ isObjectUpdated = true; break;}
        if(api_address != nullptr && *api_address != QString("")){ isObjectUpdated = true; break;}
        if(m_api_port_isSet){ isObjectUpdated = true; break;}
        if(data_address != nullptr && *data_address != QString("")){ isObjectUpdated = true; break;}
        if(m_data_port_isSet){ isObjectUpdated = true; break;}
        if(m_device_index_isSet){ isObjectUpdated = true; break;}
        if(m_channel_index_isSet){ isObjectUpdated = true; break;}
    }while(false);
    return isObjectUpdated;
}
}
