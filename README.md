camera-hal
==========

opensource camera hal 
requires:
out/target/product/pyramid/obj/KERNEL_OBJ/usr/include/media/msm_camera.h

hardware/libhardware/include/hardware
diff --git a/include/hardware/camera_common.h b/include/hardware/camera_common.h
index 3a1233f..b502569 100644
--- a/include/hardware/camera_common.h
+++ b/include/hardware/camera_common.h
@@ -174,7 +174,7 @@ typedef struct camera_info {
      *
      */
     const camera_metadata_t *static_camera_characteristics;
-} camera_info_t;
+} camera_info_t1; //conflicts with camera hal headers, so rename it temporary
 
 /**
  * camera_device_status_t:
