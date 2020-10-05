#include "tvform.h"
#include "ui_tvform.h"

#include <glib.h>
#include <gst/gst.h>
#include <gst/video/videooverlay.h>

#include <QTimer>

#define TV_SIZE_W 800  //1280
#define TV_SIZE_H 600  //720

TvForm::TvForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TvForm)
{
    ui->setupUi(this);

    GstElement *pipeline = gst_pipeline_new("xvoverlay");
    //GstElement *src = gst_element_factory_make("videotestsrc", NULL);
    GstElement *src = gst_element_factory_make("v4l2src", "src");
    GstElement *capsfilter = gst_element_factory_make("capsfilter", "capsfilter");

    //GstElement *parse = gst_element_factory_make("jpegparse", "parse"); --> can't find "jpegparse"
    GstElement *dec = gst_element_factory_make("avdec_mjpeg", "dec");

    GstElement *convert = gst_element_factory_make("videoconvert", "convert");
    GstElement *sink = gst_element_factory_make("ximagesink", "sink");

    g_object_set(G_OBJECT(capsfilter), "caps", gst_caps_new_simple("image/jpeg", "width", G_TYPE_INT, TV_SIZE_W, "height", G_TYPE_INT, TV_SIZE_H, "framerate", GST_TYPE_FRACTION, 30, 1, NULL), NULL);

    if(!src)
    {
        g_printerr("[src] elements could Not be created.\n");
        //return;
    }
    if(!capsfilter)
    {
        g_printerr("[capsfilter] elements could Not be created.\n");
        //return;
    }

    if(!dec)
    {
        g_printerr("[dec] elements could Not be created.\n");
        //return;
    }
    if(!convert)
    {
        g_printerr("[convert] elements could Not be created.\n");
        //return;
    }
    if(!sink)
    {
        g_printerr("[sink] elements could Not be created.\n");
        //return;
    }

    gst_bin_add_many(GST_BIN(pipeline), src, capsfilter, dec, convert, sink, NULL);
    if (!gst_element_link_many(src, capsfilter, dec, convert, sink, NULL))
    {
        g_printerr("Elements could not be linked.\n");
        gst_object_unref(pipeline);
        return;
    }

    g_object_set(G_OBJECT(src), "device", "/dev/video0", NULL);

    //g_object_set(G_OBJECT(src), "do-timestamp", true, NULL);

    WId xwinid;
    xwinid = this->winId();

    gst_video_overlay_set_window_handle(GST_VIDEO_OVERLAY(sink), xwinid);

    GstStateChangeReturn sret = gst_element_set_state(pipeline, GST_STATE_PLAYING);

    if( sret == GST_STATE_CHANGE_FAILURE)
    {
        gst_element_set_state(pipeline, GST_STATE_NULL);
        gst_object_unref(pipeline);

        QTimer::singleShot(0, QApplication::activeWindow(), SLOT(quit()));
    }

    this->setGeometry(20,20, TV_SIZE_W, TV_SIZE_H);
    //setWindowState(Qt::WindowMaximized);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);

}

TvForm::~TvForm()
{
    delete ui;
}
