/****************************************************************

  Generated by Eclipse Cyclone DDS IDL to C Translator
  File name: HelloWorld.h
  Source: /mnt/EAE2CD0AE2CCDBC7/cyclonedds/examples/helloworld/HelloWorld.idl
  Cyclone DDS: V0.11.0

*****************************************************************/
#ifndef DDSC_HELLOWORLD_H_9B50AF295158773C2F7FC46C5CDB07EA
#define DDSC_HELLOWORLD_H_9B50AF295158773C2F7FC46C5CDB07EA

#include "dds/ddsc/dds_public_impl.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct HelloWorld
{
  uint32_t index;
  char * message;
} HelloWorld;

extern const dds_topic_descriptor_t HelloWorld_desc;

#define HelloWorld__alloc() \
((HelloWorld*) dds_alloc (sizeof (HelloWorld)));

#define HelloWorld_free(d,o) \
dds_sample_free ((d), &HelloWorld_desc, (o))

#ifdef __cplusplus
}
#endif

#endif /* DDSC_HELLOWORLD_H_9B50AF295158773C2F7FC46C5CDB07EA */
