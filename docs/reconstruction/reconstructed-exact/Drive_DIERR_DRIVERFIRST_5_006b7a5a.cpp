// READABILITY (auto CF):
//  - Body size: ~2107 non-empty decompiler lines.
//  - Control keywords: return×629, if×384, for×47, goto×31, while×20, switch×18, do×1.
//  - Notable callees: IDirectMusicPerformance::MusicToMIDI×3, MIDIToMusic×3, MusicToMIDI×3, IDirectMusicPerformance::MIDIToMusic×2, IDirectMusicTool::ProcessPMsg×2, IPinFlowControl::Block×2, header×2, D3DXInitialize.
//  - Strings: "Access to Surface refused because Surface is obscured."; "CoInitialize has already been called."; "An undetermined error occurred"; "The function called is not supported at this time".
//  - Return sites: 629.

// =============================================================================
// Drive_DIERR_DRIVERFIRST_5_006b7a5a
// -----------------------------------------------------------------------------
// Stable ID: aa_006b7a5a
// Address:   0x006b7a5a  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "DIERR_DRIVERFIRST+5"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

char * Drive_DIERR_DRIVERFIRST_5_006b7a5a(int param_1)



{

  if (param_1 < -0x7789fe47) {

    if (param_1 == -0x7789fe48) {

      return "Access to Surface refused because Surface is obscured.";

    }

    if (param_1 < -0x7ff8fb7e) {

      if (param_1 == -0x7ff8fb7f) {

        return "The application was written for an unsupported prerelease version of DirectInput.";

      }

      if (param_1 < -0x7ffbfda6) {

        if (param_1 == -0x7ffbfda7) {

LAB_006b9e86:

          return "Cannot play back the video stream: format \'RPZA\' is not supported.";

        }

        if (param_1 < -0x7ffbfde1) {

          if (param_1 == -0x7ffbfde2) {

            return "Setting a palette would conflict with the color key already set.";

          }

          if (param_1 < -0x7ffbfdf6) {

            if (param_1 == -0x7ffbfdf7) {

              return 

              "The operation could not be completed because the device is not plugged in. & The operation cannot be performed because the pins are not connected."

              ;

            }

            if (param_1 < -0x7ffbfe0e) {

              if (param_1 == -0x7ffbfe0f) {

                return "CoInitialize has already been called.";

              }

              if (param_1 < -0x7fffbffa) {

                if (param_1 == -0x7fffbffb) {

                  return "An undetermined error occurred";

                }

                if (param_1 == -0x7ffffff6) {

                  return "The data necessary to complete this operation is not yet available.";

                }

                if (param_1 == -0x7fffbfff) {

                  return "The function called is not supported at this time";

                }

                if (param_1 == -0x7fffbffe) {

                  return "The requested COM interface is not available";

                }

                if (param_1 == -0x7fffbffd) {

                  return "Invalid pointer";

                }

                if (param_1 == -0x7fffbffc) {

                  return "Operation aborted";

                }

              }

              else {

                if (param_1 == -0x7fff0001) {

                  return "Catastrophic failure";

                }

                if (param_1 == -0x7ffbfef0) {

                  return "This object does not support aggregation";

                }

                if (param_1 == -0x7ffbfeac) {

                  return "Class not registered";

                }

                if (param_1 == -0x7ffbfe10) {

                  return "CoInitialize has not been called.";

                }

              }

            }

            else {

              switch(param_1) {

              case -0x7ffbfe00:

                return 

                "Unable to IDirectInputJoyConfig_Acquire because the user does not have sufficient privileges to change the joystick configuration. & An invalid media type was specified"

                ;

              case -0x7ffbfdff:

                return "The device is full. & An invalid media subtype was specified.";

              case -0x7ffbfdfe:

                return 

                "Not all the requested information fit into the buffer. & This object can only be created as an aggregated object."

                ;

              case -0x7ffbfdfd:

                return "The effect is not downloaded. & The enumerator has become invalid.";

              case -0x7ffbfdfc:

                return 

                "The device cannot be reinitialized because there are still effects attached to it. & At least one of the pins involved in the operation is already connected."

                ;

              case -0x7ffbfdfb:

                return 

                "The operation cannot be performed unless the device is acquired in DISCL_EXCLUSIVE mode. & This operation cannot be performed because the filter is active."

                ;

              case -0x7ffbfdfa:

                return 

                "The effect could not be downloaded because essential information is missing.  For example, no axes have been associated with the effect, or no type-specific information has been created. & One of the specified pins supports no media types."

                ;

              case -0x7ffbfdf9:

                return 

                "Attempted to read buffered device data from a device that is not buffered. & There is no common media type between these pins."

                ;

              case -0x7ffbfdf8:

                return 

                "An attempt was made to modify parameters of an effect while it is playing.  Not all hardware devices support altering the parameters of an effect while it is playing. & Two pins of the same direction cannot be connected together."

                ;

              }

            }

          }

          else {

            switch(param_1) {

            case -0x7ffbfdf6:

              return 

              "SendDeviceData failed because more information was requested to be sent than can be sent to the device.  Some devices have restrictions on how much data can be sent to them.  (For example, there might be a limit on the number of buttons that can be pressed at once.) & No sample buffer allocator is available."

              ;

            case -0x7ffbfdf5:

              return 

              "A mapper file function failed because reading or writing the user or IHV settings file failed. & A run-time error occurred."

              ;

            case -0x7ffbfdf4:

              return "No buffer space has been set";

            case -0x7ffbfdf3:

              return "The buffer is not big enough.";

            case -0x7ffbfdf2:

              return "An invalid alignment was specified.";

            case -0x7ffbfdf1:

              return "Cannot change allocated memory while the filter is active.";

            case -0x7ffbfdf0:

              return "One or more buffers are still active.";

            case -0x7ffbfdef:

              return "Cannot allocate a sample when the allocator is not active.";

            case -0x7ffbfdee:

              return "Cannot allocate memory because no size has been set.";

            case -0x7ffbfded:

              return "Cannot lock for synchronization because no clock has been defined.";

            case -0x7ffbfdec:

              return "Quality messages could not be sent because no quality sink has been defined.";

            case -0x7ffbfdeb:

              return "A required interface has not been implemented.";

            case -0x7ffbfdea:

              return "An object or name was not found.";

            case -0x7ffbfde9:

              return "No combination of intermediate filters could be found to make the connection."

              ;

            case -0x7ffbfde8:

              return "No combination of filters could be found to render the stream.";

            case -0x7ffbfde7:

              return "Could not change formats dynamically.";

            case -0x7ffbfde6:

              return "No color key has been set.";

            case -0x7ffbfde5:

              return "Current pin connection is not using the IOverlay transport.";

            case -0x7ffbfde4:

              return "Current pin connection is not using the IMemInputPin transport.";

            case -0x7ffbfde3:

              return "Setting a color key would conflict with the palette already set.";

            }

          }

        }

        else {

          switch(param_1) {

          case -0x7ffbfde1:

            return "No matching color key is available.";

          case -0x7ffbfde0:

            return "No palette is available.";

          case -0x7ffbfddf:

            return "Display does not use a palette.";

          case -0x7ffbfdde:

            return "Too many colors for the current display settings.";

          case -0x7ffbfddd:

            return "The state changed while waiting to process the sample.";

          case -0x7ffbfddc:

            return "The operation could not be performed because the filter is not stopped.";

          case -0x7ffbfddb:

            return "The operation could not be performed because the filter is not paused.";

          case -0x7ffbfdda:

            return "The operation could not be performed because the filter is not running.";

          case -0x7ffbfdd9:

            return "The operation could not be performed because the filter is in the wrong state.";

          case -0x7ffbfdd8:

            return "The sample start time is after the sample end time.";

          case -0x7ffbfdd7:

            return "The supplied rectangle is invalid.";

          case -0x7ffbfdd6:

            return "This pin cannot use the supplied media type.";

          case -0x7ffbfdd5:

            return "This sample cannot be rendered.";

          case -0x7ffbfdd4:

            return "This sample cannot be rendered because the end of the stream has been reached.";

          case -0x7ffbfdd3:

            return "An attempt to add a filter with a duplicate name failed.";

          case -0x7ffbfdd2:

            return "A time-out has expired.";

          case -0x7ffbfdd1:

            return "The file format is invalid.";

          case -0x7ffbfdd0:

            return "The list has already been exhausted.";

          case -0x7ffbfdcf:

            return "The filter graph is circular.";

          case -0x7ffbfdce:

            return "Updates are not allowed in this state.";

          case -0x7ffbfdcd:

            return "An attempt was made to queue a command for a time in the past.";

          case -0x7ffbfdcc:

            return "The queued command has already been canceled.";

          case -0x7ffbfdcb:

            return "Cannot render the file because it is corrupt.";

          case -0x7ffbfdca:

            return "An overlay advise link already exists.";

          case -0x7ffbfdc8:

            return "No full-screen modes are available.";

          case -0x7ffbfdc7:

            return "This Advise cannot be canceled because it was not successfully set.";

          case -0x7ffbfdc6:

            return "A full-screen mode is not available.";

          case -0x7ffbfdc5:

            return "Cannot call IVideoWindow methods while in full-screen mode.";

          case -0x7ffbfdc0:

            return "The media type of this file is not recognized.";

          case -0x7ffbfdbf:

            return "The source filter for this file could not be loaded.";

          case -0x7ffbfdbd:

            return "A file appeared to be incomplete.";

          case -0x7ffbfdbc:

            return "The version number of the file is invalid.";

          case -0x7ffbfdb9:

            return "This file is corrupt: it contains an invalid class identifier.";

          case -0x7ffbfdb8:

            return "This file is corrupt: it contains an invalid media type.";

          case -0x7ffbfdb7:

            return "No time stamp has been set for this sample.";

          case -0x7ffbfdaf:

            return "No media time stamp has been set for this sample.";

          case -0x7ffbfdae:

            return "No media time format has been selected.";

          case -0x7ffbfdad:

            return "Cannot change balance because audio device is mono only.";

          case -0x7ffbfdab:

switchD_006b7cfe_caseD_80040255:

            return "Cannot play back the video stream: no suitable decompressor could be found.";

          case -0x7ffbfdaa:

            return 

            "Cannot play back the audio stream: no audio hardware is available, or the hardware is not responding."

            ;

          }

        }

      }

      else if (param_1 < -0x7ffbfcff) {

        if (param_1 == -0x7ffbfd00) {

          return 

          "Device driver-specific codes. Unless the specific driver has been precisely identified, no meaning should be attributed to these values other than that the driver originated the error."

          ;

        }

        switch(param_1) {

        case -0x7ffbfda5:

          return "ActiveMovie cannot play MPEG movies on this processor.";

        case -0x7ffbfda4:

          return "Cannot play back the audio stream: the audio format is not supported.";

        case -0x7ffbfda3:

          return "Cannot play back the video stream: the video format is not supported.";

        case -0x7ffbfda2:

          return 

          "ActiveMovie cannot play this video stream because it falls outside the constrained standard."

          ;

        case -0x7ffbfda1:

          return 

          "Cannot perform the requested function on an object that is not in the filter graph.";

        case -0x7ffbfd9f:

          return 

          "Cannot get or set time related information on an object that is using a time format of TIME_FORMAT_NONE."

          ;

        case -0x7ffbfd9e:

          return 

          "The connection cannot be made because the stream is read only and the filter alters the data."

          ;

        case -0x7ffbfd9c:

          return "The buffer is not full enough.";

        case -0x7ffbfd9b:

          return "Cannot play back the file.  The format is not supported.";

        case -0x7ffbfd9a:

          return "Pins cannot connect due to not supporting the same transport.";

        case -0x7ffbfd97:

          return "The Video CD can\'t be read correctly by the device or is the data is corrupt.";

        case -0x7ffbfd8f:

          return 

          "There is not enough Video Memory at this display resolution and number of colors. Reducing resolution might help."

          ;

        case -0x7ffbfd8e:

          return "The VideoPort connection negotiation process has failed.";

        case -0x7ffbfd8d:

          return 

          "Either DirectDraw has not been installed or the Video Card capabilities are not suitable. Make sure the display is not in 16 color mode."

          ;

        case -0x7ffbfd8c:

          return "No VideoPort hardware is available, or the hardware is not responding.";

        case -0x7ffbfd8b:

          return "No Capture hardware is available, or the hardware is not responding.";

        case -0x7ffbfd8a:

          return "This User Operation is inhibited by DVD Content at this time.";

        case -0x7ffbfd89:

          return "This Operation is not permitted in the current domain.";

        case -0x7ffbfd88:

          return 

          "The specified button is invalid or is not present at the current time, or there is no button present at the specified location."

          ;

        case -0x7ffbfd87:

          return "DVD-Video playback graph has not been built yet.";

        case -0x7ffbfd86:

          return "DVD-Video playback graph building failed.";

        case -0x7ffbfd85:

          return "DVD-Video playback graph could not be built due to insufficient decoders.";

        case -0x7ffbfd84:

          return 

          "Version number of DirectDraw not suitable. Make sure to install dx5 or higher version.";

        case -0x7ffbfd83:

          return 

          "Copy protection cannot be enabled. Please make sure any other copy protected content is not being shown now."

          ;

        case -0x7ffbfd81:

          return "This object cannot be used anymore as its time has expired.";

        case -0x7ffbfd7f:

          return "The operation cannot be performed at the current playback speed.";

        case -0x7ffbfd7e:

          return "The specified menu doesn\'t exist.";

        case -0x7ffbfd7d:

          return "The specified command was either cancelled or no longer exists.";

        case -0x7ffbfd7c:

          return "The data did not contain a recognized version.";

        case -0x7ffbfd7b:

          return "The state data was corrupt.";

        case -0x7ffbfd7a:

          return "The state data is from a different disc.";

        case -0x7ffbfd79:

          return "The region was not compatible with the current drive.";

        case -0x7ffbfd78:

          return "The requested DVD stream attribute does not exist.";

        case -0x7ffbfd77:

          return "Currently there is no GoUp (Annex J user function) program chain (PGC).";

        case -0x7ffbfd76:

          return "The current parental level was too low.";

        case -0x7ffbfd75:

          return "The current audio is not karaoke content.";

        case -0x7ffbfd72:

          return "Frame step is not supported on this configuration.";

        case -0x7ffbfd71:

          return "The specified stream is disabled and cannot be selected.";

        case -0x7ffbfd70:

          return 

          "The operation depends on the current title number, however the navigator has not yet entered the VTSM or the title domains, so the \'current\' title index is unknown."

          ;

        case -0x7ffbfd6f:

          return "The specified path does not point to a valid DVD disc.";

        case -0x7ffbfd6e:

          return "There is currently no resume information.";

        case -0x7ffbfd6d:

          return 

          "This thread has already blocked this output pin.  There is no need to call IPinFlowControl::Block() again."

          ;

        case -0x7ffbfd6c:

          return 

          "IPinFlowControl::Block() has been called on another thread.  The current thread cannot make any assumptions about this pin\'s block state."

          ;

        case -0x7ffbfd6b:

          return "An operation failed due to a certification failure.";

        }

      }

      else if (param_1 < -0x7ff8fffd) {

        if (param_1 == -0x7ff8fffe) {

switchD_006b9cfb_caseD_2:

          return "The system cannot find the file specified.";

        }

        if (param_1 < -0x7ffbfbfd) {

          if (param_1 == -0x7ffbfbfe) {

            return 

            "The INF file for the selected device could not be found or is invalid or is damaged. & The specified purpose ID can\'t be used for the call."

            ;

          }

          if (param_1 < -0x7ffbfcfa) {

            if (param_1 == -0x7ffbfcfb) {

              return "DIERR_DRIVERFIRST+5";

            }

            if (param_1 == -0x7ffbfcff) {

              return "DIERR_DRIVERFIRST+1";

            }

            if (param_1 == -0x7ffbfcfe) {

              return "DIERR_DRIVERFIRST+2";

            }

            if (param_1 == -0x7ffbfcfd) {

              return "DIERR_DRIVERFIRST+3";

            }

            if (param_1 == -0x7ffbfcfc) {

              return "DIERR_DRIVERFIRST+4";

            }

          }

          else {

            if (param_1 == -0x7ffbfc0e) {

              return "A registry entry is corrupt.";

            }

            if (param_1 == -0x7ffbfc01) {

              return "Device installer errors.";

            }

            if (param_1 == -0x7ffbfc00) {

              return 

              "Registry entry or DLL for class installer invalid or class installer not found.";

            }

            if (param_1 == -0x7ffbfbff) {

              return 

              "The user cancelled the install operation. & The stream already has allocated samples and the surface doesn\'t match the sample format."

              ;

            }

          }

        }

        else {

          switch(param_1) {

          case -0x7ffbfbfd:

            return "No stream can be found with the specified attributes.";

          case -0x7ffbfbfc:

            return "Seeking not supported for this object.";

          case -0x7ffbfbfb:

            return "The stream formats are not compatible.";

          case -0x7ffbfbfa:

            return "The sample is busy.";

          case -0x7ffbfbf9:

            return 

            "The object can\'t accept the call because its initialize function or equivalent has not been called."

            ;

          case -0x7ffbfbf8:

            return "MS_E_SOURCEALREADYDEFINED";

          case -0x7ffbfbf7:

            return "The stream type is not valid for this operation.";

          case -0x7ffbfbf6:

            return "The object is not in running state.";

          }

        }

      }

      else if (param_1 < -0x7ff8ffea) {

        if (param_1 == -0x7ff8ffeb) {

LAB_006b951e:

          return "This object has not been initialized";

        }

        switch(param_1) {

        case -0x7ff8fffd:

          goto switchD_006b81cc_caseD_80070003;

        case -0x7ff8fffc:

          goto switchD_006b81cc_caseD_80070004;

        case -0x7ff8fffb:

          return "Access is denied";

        case -0x7ff8fffa:

          goto switchD_006b81cc_caseD_80070006;

        case -0x7ff8fff8:

          goto switchD_006b81cc_caseD_80070008;

        case -0x7ff8fff7:

          goto switchD_006b81cc_caseD_80070009;

        case -0x7ff8fff6:

          goto switchD_006b81cc_caseD_8007000a;

        case -0x7ff8fff5:

          goto switchD_006b81cc_caseD_8007000b;

        case -0x7ff8fff4:

          return "The operation cannot be performed unless the device is acquired.";

        case -0x7ff8fff2:

          return "Ran out of memory";

        }

      }

      else {

        if (param_1 == -0x7ff8ffe2) {

          return "Access to the device has been lost.  It must be re-acquired.";

        }

        if (param_1 == -0x7ff8ffa9) {

          return "An invalid parameter was passed to the returning function";

        }

        if (param_1 == -0x7ff8ff89) {

          return 

          "The object could not be created due to an incompatible driver version or mismatched or incomplete driver components."

          ;

        }

        if (param_1 == -0x7ff8ff56) {

          return "The operation cannot be performed while the device is acquired.";

        }

        if (param_1 == -0x7ff8fefd) {

          return "No more items.";

        }

        if (param_1 == -0x7ff8fb82) {

          return "The application requires a newer version of DirectInput.";

        }

      }

    }

    else if (param_1 < -0x7fea7caf) {

      if (param_1 == -0x7fea7cb0) {

LAB_006b87a1:

        return "Invalid group";

      }

      if (param_1 < -0x7feafe75) {

        if (param_1 == -0x7feafe76) {

          return "Transport not init";

        }

        if (param_1 < -0x7feafe8d) {

          if (param_1 == -0x7feafe8e) {

            return "Compression not supported";

          }

          if (param_1 < -0x7feafed3) {

            if (param_1 == -0x7feafed4) {

              return "Session lost";

            }

            if (param_1 < -0x7feaff87) {

              if (param_1 == -0x7feaff88) {

LAB_006b8779:

                return "Invalid flags";

              }

              if (param_1 == -0x7ff8fb70) {

                return "The specified property ID is not supported for the specified property set.";

              }

              if (param_1 == -0x7ff8fb6e) {

                return "The specified property set is not supported.";

              }

              if (param_1 == -0x7ff8fb21) goto LAB_006b953c;

              if (param_1 == -0x7feaffe2) goto LAB_006b85c8;

              if (param_1 == -0x7feaffb6) goto LAB_006b82ed;

            }

            else {

              if (param_1 == -0x7feaff7e) {

LAB_006b8818:

                return "Invalid object";

              }

              if (param_1 == -0x7feaff79) goto LAB_006b8888;

              if (param_1 == -0x7feaff6f) goto LAB_006b87a1;

              if (param_1 == -0x7feaff6a) goto switchD_006b81cc_caseD_80070006;

            }

          }

          else if (param_1 < -0x7feafe94) {

            if (param_1 == -0x7feafe95) {

              return "Not connected";

            }

            if (param_1 == -0x7feafed2) {

              return "No voice session";

            }

            if (param_1 == -0x7feafe98) {

LAB_006b8610:

              return "Connection lost";

            }

            if (param_1 == -0x7feafe97) {

              return "Not initialized";

            }

            if (param_1 == -0x7feafe96) {

              return "Connected";

            }

          }

          else {

            if (param_1 == -0x7feafe92) {

              return "Connect aborting";

            }

            if (param_1 == -0x7feafe91) goto LAB_006b8937;

            if (param_1 == -0x7feafe90) {

              return "Invalid target";

            }

            if (param_1 == -0x7feafe8f) {

              return "Transport not host";

            }

          }

        }

        else {

          switch(param_1) {

          case -0x7feafe8d:

            return "Already pending";

          case -0x7feafe8c:

            return "Sound init failure";

          case -0x7feafe8b:

            return "Time out";

          case -0x7feafe8a:

            return "Connect aborted";

          case -0x7feafe89:

            return "No 3d sound";

          case -0x7feafe88:

            return "Already buffered";

          case -0x7feafe87:

            return "Not buffered";

          case -0x7feafe86:

switchD_006b83fc_caseD_8015017a:

            return "Hosting";

          case -0x7feafe85:

            return "Not hosting";

          case -0x7feafe84:

switchD_006b83fc_caseD_8015017c:

            return "Invalid device";

          case -0x7feafe83:

            return "Record system error";

          case -0x7feafe82:

            return "Playback system error";

          case -0x7feafe81:

            return "Send error";

          case -0x7feafe80:

switchD_006b83fc_caseD_80150180:

            return "User cancel";

          case -0x7feafe7d:

            return "Run setup";

          case -0x7feafe7c:

            return "Incompatible version";

          case -0x7feafe79:

            return "Initialized";

          case -0x7feafe78:

            return "No transport";

          case -0x7feafe77:

            return "No callback";

          }

        }

      }

      else if (param_1 < -0x7fea7e8f) {

        if (param_1 == -0x7fea7e90) {

          return "Conversion";

        }

        if (param_1 < -0x7fea7f8f) {

          if (param_1 == -0x7fea7f90) {

            return "Already disconnecting";

          }

          if (param_1 < -0x7feafe6f) {

            if (param_1 == -0x7feafe70) {

              return "Locked buffer";

            }

            if (param_1 == -0x7feafe75) {

              return "Transport no session";

            }

            if (param_1 == -0x7feafe74) {

              return "Transport no player";

            }

            if (param_1 == -0x7feafe73) {

              return "User back";

            }

            if (param_1 == -0x7feafe72) {

              return "No rec vol available";

            }

            if (param_1 == -0x7feafe71) {

              return "Invalid buffer";

            }

          }

          else {

            if (param_1 == -0x7fea7fd0) {

              return "Aborted";

            }

            if (param_1 == -0x7fea7fc0) {

              return "Addressing";

            }

            if (param_1 == -0x7fea7fb0) {

              return "Already closing";

            }

            if (param_1 == -0x7fea7fa0) {

              return "Already connected";

            }

          }

        }

        else if (param_1 < -0x7fea7edf) {

          if (param_1 == -0x7fea7ee0) {

            return "Cant create group";

          }

          if (param_1 == -0x7fea7f80) {

            return "Already initialized";

          }

          if (param_1 == -0x7fea7f70) {

            return "Already registered";

          }

          if (param_1 == -0x7fea7f00) {

LAB_006b85c8:

            return "Buffer too small";

          }

          if (param_1 == -0x7fea7ef0) {

            return "Can not cancel";

          }

        }

        else {

          if (param_1 == -0x7fea7ed0) {

            return "Cant create player";

          }

          if (param_1 == -0x7fea7ec0) {

            return "Cant launch application";

          }

          if (param_1 == -0x7fea7eb0) {

            return "Connecting";

          }

          if (param_1 == -0x7fea7ea0) goto LAB_006b8610;

        }

      }

      else if (param_1 < -0x7fea7daf) {

        if (param_1 == -0x7fea7db0) goto switchD_006b83fc_caseD_8015017a;

        if (param_1 < -0x7fea7dff) {

          if (param_1 == -0x7fea7e00) {

            return "End point not receiving";

          }

          if (param_1 == -0x7fea7e8b) {

            return "Data too large";

          }

          if (param_1 == -0x7fea7e80) {

            return "Does not exist";

          }

          if (param_1 == -0x7fea7e7b) {

            return "dpnsvr not available";

          }

          if (param_1 == -0x7fea7e70) {

            return "Duplicate command";

          }

        }

        else {

          if (param_1 == -0x7fea7df0) {

            return "Enum query too large";

          }

          if (param_1 == -0x7fea7de0) {

            return "Enum response too large";

          }

          if (param_1 == -0x7fea7dd0) {

LAB_006b82ed:

            return "Exception";

          }

          if (param_1 == -0x7fea7dc0) {

            return "Group not empty";

          }

        }

      }

      else if (param_1 < -0x7fea7cff) {

        if (param_1 == -0x7fea7d00) {

          return "Invalid application";

        }

        if (param_1 == -0x7fea7da0) {

          return "Host rejected connection";

        }

        if (param_1 == -0x7fea7d90) {

          return "Host terminated session";

        }

        if (param_1 == -0x7fea7d80) {

          return "Incomplete address";

        }

        if (param_1 == -0x7fea7d70) {

          return "Invalid address format";

        }

      }

      else {

        if (param_1 == -0x7fea7cf0) {

          return "Invalid command";

        }

        if (param_1 == -0x7fea7ce0) {

          return "Invalid device address";

        }

        if (param_1 == -0x7fea7cd0) {

          return "Invalid end point";

        }

        if (param_1 == -0x7fea7cc0) goto LAB_006b8779;

      }

    }

    else if (param_1 < -0x7789ff7d) {

      if (param_1 == -0x7789ff7e) {

        return "DirectDraw received a pointer that was an invalid DIRECTDRAW object.";

      }

      if (param_1 < -0x7fea7a9f) {

        if (param_1 == -0x7fea7aa0) {

          return "Player already in group";

        }

        if (param_1 < -0x7fea7b9f) {

          if (param_1 == -0x7fea7ba0) {

            return "Invalid version";

          }

          if (param_1 < -0x7fea7bef) {

            if (param_1 == -0x7fea7bf0) {

              return "Invalid password";

            }

            if (param_1 == -0x7fea7ca0) {

switchD_006b81cc_caseD_80070006:

              return "Invalid handle";

            }

            if (param_1 == -0x7fea7c90) {

              return "Invalid host address";

            }

            if (param_1 == -0x7fea7c80) {

              return "Invalid instance";

            }

            if (param_1 == -0x7fea7c70) {

              return "Invalid interface";

            }

            if (param_1 == -0x7fea7c00) goto LAB_006b8818;

          }

          else {

            if (param_1 == -0x7fea7be0) {

LAB_006b8888:

              return "Invalid player";

            }

            if (param_1 == -0x7fea7bd0) {

              return "Invalid priority";

            }

            if (param_1 == -0x7fea7bc0) {

              return "Invalid string";

            }

            if (param_1 == -0x7fea7bb0) {

              return "Invalid url";

            }

          }

        }

        else if (param_1 < -0x7fea7aef) {

          if (param_1 == -0x7fea7af0) {

            return "No response";

          }

          if (param_1 == -0x7fea7b90) {

            return "No caps";

          }

          if (param_1 == -0x7fea7b80) {

            return "No connection";

          }

          if (param_1 == -0x7fea7b70) {

            return "No host player";

          }

          if (param_1 == -0x7fea7b00) {

            return "No more address components";

          }

        }

        else {

          if (param_1 == -0x7fea7ae0) {

LAB_006b8937:

            return "Not allowed";

          }

          if (param_1 == -0x7fea7ad0) {

            return "Not host";

          }

          if (param_1 == -0x7fea7ac0) {

            return "Not ready";

          }

          if (param_1 == -0x7fea7ab0) {

            return "Not registered";

          }

        }

      }

      else if (param_1 < -0x7789fffa) {

        if (param_1 == -0x7789fffb) {

LAB_006b953c:

          return "This object is already initialized";

        }

        if (param_1 < -0x7fea79ef) {

          if (param_1 == -0x7fea79f0) {

            return "Session full";

          }

          if (param_1 == -0x7fea7a90) {

            return "Player lost";

          }

          if (param_1 == -0x7fea7a80) {

            return "Player not in group";

          }

          if (param_1 == -0x7fea7a70) {

            return "Player not reachable";

          }

          if (param_1 == -0x7fea7a00) {

            return "Send too large";

          }

        }

        else {

          if (param_1 == -0x7fea79e0) {

            return "Table full";

          }

          if (param_1 == -0x7fea79d0) {

            return "Timed out";

          }

          if (param_1 == -0x7fea79c0) {

            return "Uninitialized";

          }

          if (param_1 == -0x7fea79b0) goto switchD_006b83fc_caseD_80150180;

        }

      }

      else if (param_1 < -0x7789ffa5) {

        if (param_1 == -0x7789ffa6) {

          return "Height of rectangle provided is not a multiple of reqd alignment";

        }

        if (param_1 == -0x7789fff6) {

          return "This surface can not be attached to the requested surface.";

        }

        if (param_1 == -0x7789ffec) {

          return "This surface can not be detached from the requested surface.";

        }

        if (param_1 == -0x7789ffd8) {

          return "Support is currently not available.";

        }

        if (param_1 == -0x7789ffc9) {

          return "An exception was encountered while performing the requested operation";

        }

      }

      else {

        if (param_1 == -0x7789ffa1) {

          return "Unable to match primary surface creation request with existing primary surface.";

        }

        if (param_1 == -0x7789ff9c) {

          return "One or more of the caps bits passed to the callback are incorrect.";

        }

        if (param_1 == -0x7789ff92) {

          return "DirectDraw does not support provided Cliplist.";

        }

        if (param_1 == -0x7789ff88) {

          return "DirectDraw does not support the requested mode";

        }

      }

    }

    else if (param_1 < -0x7789fee7) {

      if (param_1 == -0x7789fee8) {

        return 

        "Operation could not be carried out because there is no appropriate raster op hardware present or available."

        ;

      }

      if (param_1 < -0x7789ff28) {

        if (param_1 == -0x7789ff29) {

          return "Surface doesn\'t currently have a color key";

        }

        if (param_1 < -0x7789ff4a) {

          if (param_1 == -0x7789ff4b) {

            return 

            "Operation could not be carried out because there is no stereo hardware present or available."

            ;

          }

          if (param_1 == -0x7789ff6f) {

            return "pixel format was invalid as specified";

          }

          if (param_1 == -0x7789ff6a) {

            return "Rectangle provided was invalid.";

          }

          if (param_1 == -0x7789ff60) {

            return "Operation could not be carried out because one or more surfaces are locked";

          }

          if (param_1 == -0x7789ff56) {

            return "There is no 3D present.";

          }

          if (param_1 == -0x7789ff4c) {

            return 

            "Operation could not be carried out because there is no alpha accleration hardware present or available."

            ;

          }

        }

        else {

          if (param_1 == -0x7789ff4a) {

            return 

            "Operation could not be carried out because there is no hardware present which supports stereo surfaces"

            ;

          }

          if (param_1 == -0x7789ff33) {

            return "no clip list available";

          }

          if (param_1 == -0x7789ff2e) {

            return 

            "Operation could not be carried out because there is no color conversion hardware present or available."

            ;

          }

          if (param_1 == -0x7789ff2c) {

            return 

            "Create function called without DirectDraw object method SetCooperativeLevel being called."

            ;

          }

        }

      }

      else if (param_1 < -0x7789ff0f) {

        if (param_1 == -0x7789ff10) {

          return "There is no GDI present.";

        }

        if (param_1 == -0x7789ff24) {

          return 

          "Operation could not be carried out because there is no hardware support of the dest color key."

          ;

        }

        if (param_1 == -0x7789ff22) {

          return "No DirectDraw support possible with current display driver";

        }

        if (param_1 == -0x7789ff1f) {

          return 

          "Operation requires the application to have exclusive mode but the application does not have exclusive mode."

          ;

        }

        if (param_1 == -0x7789ff1a) {

          return "Flipping visible surfaces is not supported.";

        }

      }

      else {

        if (param_1 == -0x7789ff06) {

          return 

          "Operation could not be carried out because there is no hardware present or available.";

        }

        if (param_1 == -0x7789ff01) {

          return "Requested item was not found";

        }

        if (param_1 == -0x7789fefc) {

          return 

          "Operation could not be carried out because there is no overlay hardware present or available."

          ;

        }

        if (param_1 == -0x7789fef2) {

          return 

          "Operation could not be carried out because the source and destination rectangles are on the same surface and overlap each other."

          ;

        }

      }

    }

    else if (param_1 < -0x7789fe97) {

      if (param_1 == -0x7789fe98) {

        return "The hardware needed for the requested operation has already been allocated.";

      }

      if (param_1 < -0x7789febf) {

        if (param_1 == -0x7789fec0) {

          return 

          "DirectDraw Surface is not in 8 bit color mode and the requested operation requires 8 bit color."

          ;

        }

        if (param_1 == -0x7789fede) {

          return 

          "Operation could not be carried out because there is no rotation hardware present or available."

          ;

        }

        if (param_1 == -0x7789feca) {

          return 

          "Operation could not be carried out because there is no hardware support for stretching";

        }

        if (param_1 == -0x7789fec4) {

          return 

          "DirectDrawSurface is not in 4 bit color palette and the requested operation requires 4 bit color palette."

          ;

        }

        if (param_1 == -0x7789fec3) {

          return 

          "DirectDrawSurface is not in 4 bit color index palette and the requested operation requires 4 bit color index palette."

          ;

        }

      }

      else {

        if (param_1 == -0x7789feb6) {

          return 

          "Operation could not be carried out because there is no texture mapping hardware present or available."

          ;

        }

        if (param_1 == -0x7789feb1) {

          return 

          "Operation could not be carried out because there is no hardware support for vertical blank synchronized operations."

          ;

        }

        if (param_1 == -0x7789feac) {

          return 

          "Operation could not be carried out because there is no hardware support for zbuffer blting."

          ;

        }

        if (param_1 == -0x7789fea2) {

          return 

          "Overlay surfaces could not be z layered based on their BltOrder because the hardware does not support z layering of overlays."

          ;

        }

      }

    }

    else if (param_1 < -0x7789fe6f) {

      if (param_1 == -0x7789fe70) {

        return "No src color key specified for this operation.";

      }

      if (param_1 == -0x7789fe84) {

        return "Out of video memory";

      }

      if (param_1 == -0x7789fe82) {

        return "hardware does not support clipped overlays";

      }

      if (param_1 == -0x7789fe80) {

        return "Can only have ony color key active at one time for overlays";

      }

      if (param_1 == -0x7789fe7d) {

        return 

        "Access to this palette is being refused because the palette is already locked by another thread."

        ;

      }

    }

    else {

      if (param_1 == -0x7789fe66) {

        return "This surface is already attached to the surface it is being attached to.";

      }

      if (param_1 == -0x7789fe5c) {

        return 

        "This surface is already a dependency of the surface it is being made a dependency of.";

      }

      if (param_1 == -0x7789fe52) {

        return 

        "Access to this surface is being refused because the surface is already locked by another thread."

        ;

      }

      if (param_1 == -0x7789fe4d) {

        return 

        "Access to this surface is being refused because no driver exists which can supply a pointer to the surface. This is most likely to happen when attempting to lock the primary surface when no DCI provider is present. Will also happen on attempts to lock an optimized surface."

        ;

      }

    }

  }

  else if (param_1 < -0x7787eecf) {

    if (param_1 == -0x7787eed0) {

      return "An attempt was made to close the software synthesizer while it was already  open.";

    }

    if (param_1 < -0x7789fc71) {

      if (param_1 == -0x7789fc72) {

        return "Bad file float size";

      }

      if (param_1 < -0x7789fdb2) {

        if (param_1 == -0x7789fdb3) {

          return "The surface being used is not a palette-based surface";

        }

        switch(param_1) {

        case -0x7789fe3e:

          return 

          "Access to this surface is being refused because the surface is gone. The DIRECTDRAWSURFACE object representing this surface should have Restore called on it."

          ;

        case -0x7789fe34:

          return "The requested surface is not attached.";

        case -0x7789fe2a:

          return "Height requested by DirectDraw is too large.";

        case -0x7789fe20:

          return 

          "Size requested by DirectDraw is too large --  The individual height and width are OK.";

        case -0x7789fe16:

          return "Width requested by DirectDraw is too large.";

        case -0x7789fe02:

          return "Pixel format requested is unsupported by DirectDraw";

        case -0x7789fdf8:

          return "Bitmask in the pixel format requested is unsupported by DirectDraw";

        case -0x7789fdf7:

          return "The specified stream contains invalid data";

        case -0x7789fde7:

          return "vertical blank is in progress";

        case -0x7789fde4:

          return "Was still drawing";

        case -0x7789fde2:

          return "The specified surface type requires specification of the COMPLEX flag";

        case -0x7789fdd0:

          return "Rectangle provided was not horizontally aligned on reqd. boundary";

        case -0x7789fdcf:

          return "The GUID passed to DirectDrawCreate is not a valid DirectDraw driver identifier.";

        case -0x7789fdce:

          return 

          "A DirectDraw object representing this driver has already been created for this process.";

        case -0x7789fdcd:

          return 

          "A hardware only DirectDraw object creation was attempted but the driver did not support any hardware."

          ;

        case -0x7789fdcc:

          return "this process already has created a primary surface";

        case -0x7789fdcb:

          return "software emulation not available.";

        case -0x7789fdca:

          return "region passed to Clipper::GetClipList is too small.";

        case -0x7789fdc9:

          return 

          "an attempt was made to set a clip list for a clipper objec that is already monitoring an hwnd."

          ;

        case -0x7789fdc8:

          return "No clipper object attached to surface object";

        case -0x7789fdc7:

          return 

          "Clipper notification requires an HWND or no HWND has previously been set as the CooperativeLevel HWND."

          ;

        case -0x7789fdc6:

          return 

          "HWND used by DirectDraw CooperativeLevel has been subclassed, this prevents DirectDraw from restoring state."

          ;

        case -0x7789fdc5:

          return 

          "The CooperativeLevel HWND has already been set. It can not be reset while the process has surfaces or palettes created."

          ;

        case -0x7789fdc4:

          return "No palette object attached to this surface.";

        case -0x7789fdc3:

          return "No hardware support for 16 or 256 color palettes.";

        case -0x7789fdc2:

          return "If a clipper object is attached to the source surface passed into a BltFast call."

          ;

        case -0x7789fdc1:

          return "No blter.";

        case -0x7789fdc0:

          return "No DirectDraw ROP hardware.";

        case -0x7789fdbf:

          return "returned when GetOverlayPosition is called on a hidden overlay";

        case -0x7789fdbe:

          return 

          "returned when GetOverlayPosition is called on a overlay that UpdateOverlay has never been called on to establish a destionation."

          ;

        case -0x7789fdbd:

          return 

          "returned when the position of the overlay on the destionation is no longer legal for that destionation."

          ;

        case -0x7789fdbc:

          return "returned when an overlay member is called for a non-overlay surface";

        case -0x7789fdbb:

          return 

          "An attempt was made to set the cooperative level when it was already set to exclusive.";

        case -0x7789fdba:

          return "An attempt has been made to flip a surface that is not flippable.";

        case -0x7789fdb9:

          return "Can\'t duplicate primary & 3D surfaces, or surfaces that are implicitly created.";

        case -0x7789fdb8:

          return 

          "Surface was not locked.  An attempt to unlock a surface that was not locked at all, or by this process, has been attempted."

          ;

        case -0x7789fdb7:

          return 

          "Windows can not create any more DCs, or a DC was requested for a paltte-indexed surface when the surface had no palette AND the display mode was not palette-indexed (in this case DirectDraw cannot select a proper palette into the DC)"

          ;

        case -0x7789fdb6:

          return "No DC was ever created for this surface.";

        case -0x7789fdb5:

          return "This surface can not be restored because it was created in a different mode.";

        case -0x7789fdb4:

          return "This surface can not be restored because it is an implicitly created surface.";

        }

      }

      else if (param_1 < -0x7789fd44) {

        if (param_1 == -0x7789fd45) {

          return 

          "Surfaces created by one direct draw device cannot be used directly by another direct draw device."

          ;

        }

        if (param_1 < -0x7789fd6b) {

          if (param_1 == -0x7789fd6c) {

            return "The attempt to page unlock a surface failed.";

          }

          if (param_1 < -0x7789fda5) {

            if (param_1 == -0x7789fda6) {

              return 

              "Attempt was made to create or set a device window without first setting the focus window"

              ;

            }

            if (param_1 == -0x7789fdb2) {

              return "The display is currently in an unsupported mode";

            }

            if (param_1 == -0x7789fdb1) {

              return 

              "Operation could not be carried out because there is no mip-map texture mapping hardware present or available."

              ;

            }

            if (param_1 == -0x7789fdb0) {

              return 

              "The requested action could not be performed because the surface was of the wrong type."

              ;

            }

            if (param_1 == -0x7789fda8) {

              return 

              "Device does not support optimized surfaces, therefore no video memory optimized surfaces"

              ;

            }

            if (param_1 == -0x7789fda7) {

              return "Surface is an optimized surface, but has not yet been allocated any memory";

            }

          }

          else {

            if (param_1 == -0x7789fda5) {

              return "Attempt was made to set a palette on a mipmap sublevel";

            }

            if (param_1 == -0x7789fd94) {

              return 

              "A DC has already been returned for this surface. Only one DC can be retrieved per surface."

              ;

            }

            if (param_1 == -0x7789fd8a) {

              return 

              "An attempt was made to allocate non-local video memory from a device that does not support non-local video memory."

              ;

            }

            if (param_1 == -0x7789fd80) {

              return "The attempt to page lock a surface failed.";

            }

          }

        }

        else {

          switch(param_1) {

          case -0x7789fd58:

            return "An attempt was made to page unlock a surface with no outstanding page locks.";

          case -0x7789fd4e:

            return "There is more data available than the specified buffer size could hold";

          case -0x7789fd4d:

            return "The data has expired and is therefore no longer valid.";

          case -0x7789fd4c:

            return "The mode test has finished executing.";

          case -0x7789fd4b:

            return "The mode test has switched to a new mode.";

          case -0x7789fd4a:

            return "D3D has not yet been initialized.";

          case -0x7789fd49:

            return "The video port is not active";

          case -0x7789fd48:

            return "The monitor does not have EDID data.";

          case -0x7789fd47:

            return "The driver does not enumerate display mode refresh rates.";

          }

        }

      }

      else {

        switch(param_1) {

        case -0x7789fc9c:

switchD_006b911e_caseD_88760364:

          return "Bad array size";

        case -0x7789fc9b:

switchD_006b911e_caseD_88760365:

          return "Bad data reference";

        case -0x7789fc9a:

          return "Internal error";

        case -0x7789fc99:

switchD_006b911e_caseD_88760367:

          return "No more objects";

        case -0x7789fc98:

          return "Bad intrinsics";

        case -0x7789fc97:

          return "No more stream handles";

        case -0x7789fc96:

switchD_006b911e_caseD_8876036a:

          return "No more data";

        case -0x7789fc95:

switchD_006b911e_caseD_8876036b:

          return "Bad cache file";

        case -0x7789fc94:

          return "No internet";

        case -0x7789fc7c:

          return "Bad object";

        case -0x7789fc7b:

          return "Bad value";

        case -0x7789fc7a:

          return "Bad type";

        case -0x7789fc79:

switchD_006b911e_caseD_88760387:

          return "Not found";

        case -0x7789fc78:

          return "Not done yet";

        case -0x7789fc77:

          return "File not found";

        case -0x7789fc76:

          return "Resource not found";

        case -0x7789fc75:

          return "Bad resource";

        case -0x7789fc74:

          return "Bad file type";

        case -0x7789fc73:

          return "Bad file version";

        }

      }

    }

    else if (param_1 < -0x7787ff9b) {

      if (param_1 == -0x7787ff9c) {

        return "The specified WAVE format is not supported";

      }

      if (param_1 < -0x7789f798) {

        if (param_1 == -0x7789f799) {

          return "More data";

        }

        if (param_1 < -0x7789f7e4) {

          if (param_1 == -0x7789f7e5) {

            return "Unsupported alpha operation";

          }

          if (param_1 < -0x7789fc6b) {

            if (param_1 == -0x7789fc6c) goto switchD_006b911e_caseD_8876036a;

            if (param_1 == -0x7789fc71) {

              return "Bad file";

            }

            if (param_1 == -0x7789fc70) {

              return "Parse error";

            }

            if (param_1 == -0x7789fc6f) goto switchD_006b911e_caseD_88760364;

            if (param_1 == -0x7789fc6e) goto switchD_006b911e_caseD_88760365;

            if (param_1 == -0x7789fc6d) goto switchD_006b911e_caseD_88760367;

          }

          else {

            if (param_1 == -0x7789fc6b) goto switchD_006b911e_caseD_8876036b;

            if (param_1 == -0x7789f7e8) {

              return "Wrong texture format";

            }

            if (param_1 == -0x7789f7e7) {

              return "Unsupported color operation";

            }

            if (param_1 == -0x7789f7e6) {

              return "Unsupported color arg";

            }

          }

        }

        else if (param_1 < -0x7789f7de) {

          if (param_1 == -0x7789f7df) {

            return "Conflicting render state";

          }

          if (param_1 == -0x7789f7e4) {

            return "Unsupported alpha arg";

          }

          if (param_1 == -0x7789f7e3) {

            return "Too many operations";

          }

          if (param_1 == -0x7789f7e2) {

            return "Conflicting texture filter";

          }

          if (param_1 == -0x7789f7e1) {

            return "Unsupported factor value";

          }

        }

        else {

          if (param_1 == -0x7789f7de) {

            return "Unsupported texture filter";

          }

          if (param_1 == -0x7789f7da) {

            return "Conflicting texture palette";

          }

          if (param_1 == -0x7789f7d9) {

            return "Driver internal error";

          }

          if (param_1 == -0x7789f79a) goto switchD_006b911e_caseD_88760387;

        }

      }

      else if (param_1 < -0x7789f4a8) {

        if (param_1 == -0x7789f4a9) {

          return "Skinning not supported";

        }

        if (param_1 < -0x7789f793) {

          if (param_1 == -0x7789f794) {

            return "Invalid call";

          }

          if (param_1 == -0x7789f798) {

            return "Device lost";

          }

          if (param_1 == -0x7789f797) {

            return "Device not reset";

          }

          if (param_1 == -0x7789f796) {

            return "Not available";

          }

          if (param_1 == -0x7789f795) goto switchD_006b83fc_caseD_8015017c;

        }

        else {

          if (param_1 == -0x7789f793) {

            return "Driver invalid call";

          }

          if (param_1 == -0x7789f4ac) {

            return "Can not modify index buffer";

          }

          if (param_1 == -0x7789f4ab) {

            return "Invalid mesh";

          }

          if (param_1 == -0x7789f4aa) {

            return "Cannot attr sort";

          }

        }

      }

      else if (param_1 < -0x7789f4a3) {

        if (param_1 == -0x7789f4a4) {

          return "Can Not remove last item";

        }

        if (param_1 == -0x7789f4a8) {

          return "Too many influences";

        }

        if (param_1 == -0x7789f4a7) {

          return "Invalid data";

        }

        if (param_1 == -0x7789f4a6) {

          return "Loaded mesh has no data";

        }

        if (param_1 == -0x7789f4a5) {

          return "Duplicate named fragment";

        }

      }

      else {

        if (param_1 == -0x7787fff6) {

          return 

          "The call failed because resources (such as a priority level) were already being used by another caller"

          ;

        }

        if (param_1 == -0x7787ffe2) {

          return "The control (vol, pan, etc.) requested by the caller is not available";

        }

        if (param_1 == -0x7787ffce) {

          return "This call is not valid for the current state of this object";

        }

        if (param_1 == -0x7787ffba) {

          return "The caller does not have the priority level required for the function to succeed";

        }

      }

    }

    else if (param_1 < -0x7787eeea) {

      if (param_1 == -0x7787eeeb) {

        return "The IStream* doesn\'t support Seek().";

      }

      if (param_1 < -0x7787eefd) {

        if (param_1 == -0x7787eefe) {

          return 

          "The requested operation cannot be performed while there are  instantiated ports in any process in the system."

          ;

        }

        if (param_1 < -0x7787ff4b) {

          if (param_1 == -0x7787ff4c) {

            return 

            "Tried to create a DSBCAPS_CTRLFX buffer shorter than DSBSIZE_FX_MIN milliseconds";

          }

          if (param_1 == -0x7787ff88) {

            return "No sound driver is available for use";

          }

          if (param_1 == -0x7787ff7e) goto LAB_006b953c;

          if (param_1 == -0x7787ff6a) {

            return "The buffer memory has been lost, and must be restored";

          }

          if (param_1 == -0x7787ff60) {

            return "Another app has a higher priority level, preventing this call from succeeding";

          }

          if (param_1 == -0x7787ff56) goto LAB_006b951e;

        }

        else {

          if (param_1 == -0x7787ff42) {

            return "Attempt to use DirectSound 8 functionality on an older DirectSound object";

          }

          if (param_1 == -0x7787ff38) {

            return "A circular loop of send effects was detected";

          }

          if (param_1 == -0x7787ff2e) {

            return "The GUID specified in an audiopath file does not match a valid MIXIN buffer";

          }

          if (param_1 == -0x7787eeff) {

            return 

            "An unexpected error was returned from a device driver, indicating possible failure of the driver or hardware."

            ;

          }

        }

      }

      else {

        switch(param_1) {

        case -0x7787eefd:

          return 

          "The requested device is already in use (possibly by a non-DirectMusic client) and cannot be opened again."

          ;

        case -0x7787eefc:

          return "Buffer is not large enough for requested operation.";

        case -0x7787eefb:

          return "No buffer was prepared for the download data.";

        case -0x7787eefa:

          return "Download failed due to inability to access or create download buffer.";

        case -0x7787eef8:

          return "Error parsing DLS collection. File is corrupt.";

        case -0x7787eef7:

          return "Wave chunks in DLS collection file are at incorrect offsets.";

        case -0x7787eeef:

          return "Second attempt to load a DLS collection that is currently open. ";

        case -0x7787eeed:

          return "Error reading wave data from DLS collection. Indicates bad file.";

        case -0x7787eeec:

          return "There is no instrument in the collection that matches patch number.";

        }

      }

    }

    else {

      switch(param_1) {

      case -0x7787eeea:

        return "The IStream* doesn\'t support Write().";

      case -0x7787eee9:

        return "The RIFF parser doesn\'t contain a required chunk while parsing file.";

      case -0x7787eee7:

        return "Invalid download id was used in the process of creating a download buffer.";

      case -0x7787eee0:

        return "Tried to unload an object that was not downloaded or previously unloaded.";

      case -0x7787eedf:

        return "Buffer was already downloaded to synth.";

      case -0x7787eede:

        return "The specified property item was not recognized by the target object.";

      case -0x7787eedd:

        return "The specified property item may not be set on the target object.";

      case -0x7787eedc:

        return "* The specified property item may not be retrieved from the target object.";

      case -0x7787eedb:

        return "Wave chunk has more than one interleaved channel. DLS format requires MONO.";

      case -0x7787eeda:

        return "Invalid articulation chunk in DLS collection.";

      case -0x7787eed9:

        return "Invalid instrument chunk in DLS collection.";

      case -0x7787eed8:

        return "Wavelink chunk in DLS collection points to invalid wave.";

      case -0x7787eed7:

        return "Articulation missing from instrument in DLS collection.";

      case -0x7787eed6:

        return "Downoaded DLS wave is not in PCM format. ";

      case -0x7787eed5:

        return "Bad wave chunk in DLS collection";

      case -0x7787eed4:

        return "Offset Table for download buffer has errors. ";

      case -0x7787eed3:

        return "Attempted to download unknown data type.";

      case -0x7787eed2:

        return 

        "The operation could not be completed because no sink was connected to the synthesizer.";

      case -0x7787eed1:

        return "An attempt was made to open the software synthesizer while it was already  open.";

      }

    }

  }

  else if (param_1 < -0x7787ee8f) {

    if (param_1 == -0x7787ee90) {

      return 

      "There is no master clock in the performance. Be sure to call IDirectMusicPerformance::Init()."

      ;

    }

    switch(param_1) {

    case -0x7787eecf:

      return 

      "The operation could not be completed because the software synth has not  yet been fully configured."

      ;

    case -0x7787eece:

      return "The operation cannot be carried out while the synthesizer is active.";

    case -0x7787eecd:

      return "An error occurred while attempting to read from the IStream* object.";

    case -0x7787eecc:

      return 

      "The operation cannot be performed because the final instance of the DirectMusic object was released. Ports cannot be used after final  release of the DirectMusic object."

      ;

    case -0x7787eecb:

      return "There was no data in the referenced buffer.";

    case -0x7787eeca:

      return "There is insufficient space to insert the given event into the buffer.";

    case -0x7787eec9:

      return "The given operation could not be carried out because the port is a capture port.";

    case -0x7787eec8:

      return "The given operation could not be carried out because the port is a render port.";

    case -0x7787eec7:

      return 

      "The port could not be created because no DirectSound has been specified. Specify a DirectSound interface via the IDirectMusic::SetDirectSound method; pass NULL to have DirectMusic manage usage of DirectSound."

      ;

    case -0x7787eec6:

      return "The operation cannot be carried out while the port is active.";

    case -0x7787eec5:

      return "Invalid DirectSound buffer was handed to port. ";

    case -0x7787eec4:

      return "Invalid buffer format was handed to the synth sink.";

    case -0x7787eec3:

      return "The operation cannot be carried out while the synthesizer is inactive.";

    case -0x7787eec2:

      return 

      "IDirectMusic::SetDirectSound has already been called. It may not be changed while in use.";

    case -0x7787eec1:

      return 

      "The given event is invalid (either it is not a valid MIDI message or it makes use of running status). The event cannot be packed into the buffer."

      ;

    case -0x7787eeb0:

      return "The IStream* object does not contain data supported by the loading object.";

    case -0x7787eeaf:

      return "The object has already been initialized.";

    case -0x7787eeae:

      return "The file does not contain a valid band.";

    case -0x7787eeab:

      return 

      "The IStream* object\'s data does not have a track header as the first chunk, and therefore can not be read by the segment object."

      ;

    case -0x7787eeaa:

      return 

      "The IStream* object\'s data does not have a tool header as the first chunk, and therefore can not be read by the graph object."

      ;

    case -0x7787eea9:

      return 

      "The IStream* object\'s data contains an invalid track header (ckid is 0 and fccType is NULL,) and therefore can not be read by the segment object."

      ;

    case -0x7787eea8:

      return 

      "The IStream* object\'s data contains an invalid tool header (ckid is 0 and fccType is NULL,) and therefore can not be read by the graph object."

      ;

    case -0x7787eea7:

      return 

      "The graph object was unable to load all tools from the IStream* object data. This may be due to errors in the stream, or the tools being incorrectly registered on the client."

      ;

    case -0x7787eea0:

      return 

      "The segment object was unable to load all tracks from the IStream* object data. This may be due to errors in the stream, or the tracks being incorrectly registered on the client."

      ;

    case -0x7787ee9f:

      return "The object requested was not found (numerically equal to DMUS_E_NOT_FOUND)";

    case -0x7787ee9e:

      return "A required object is not initialized or failed to initialize.";

    case -0x7787ee9d:

      return 

      "The requested parameter type is currently disabled. Parameter types may be enabled and disabled by certain calls to SetParam()."

      ;

    case -0x7787ee9c:

      return "The requested parameter type is not supported on the object.";

    case -0x7787ee9b:

      return "The time is in the past, and the operation can not succeed.";

    case -0x7787ee9a:

      return "The requested track is not contained by the segment.";

    case -0x7787ee99:

      return "The track does not support clock time playback or getparam.";

    }

  }

  else if (param_1 < -0x3788f433) {

    if (param_1 == -0x3788f434) {

      return "The image file format is unrecognized";

    }

    if (param_1 < -0x7787eddc) {

      if (param_1 == -0x7787eddd) {

        return 

        "A script written in AudioVBScript could not be read because it contained a statement that is not allowed by the AudioVBScript language."

        ;

      }

      if (param_1 < -0x7787edee) {

        if (param_1 == -0x7787edef) {

          return "An attempt to use this object failed because it first needs to be loaded.";

        }

        if (param_1 < -0x7787edfe) {

          if (param_1 == -0x7787edff) {

            return "The tool is already contained in the graph. Create a new instance.";

          }

          if (param_1 < -0x7787ee7b) {

            if (param_1 == -0x7787ee7c) {

              return "Unable to find or create object.";

            }

            if (param_1 == -0x7787ee80) {

              return "The class id field is required and missing in the DMUS_OBJECTDESC.";

            }

            if (param_1 == -0x7787ee7f) {

              return "The requested file path is invalid.";

            }

            if (param_1 == -0x7787ee7e) {

              return "File open failed - either file doesn\'t exist or is locked.";

            }

            if (param_1 == -0x7787ee7d) {

              return "Search data type is not supported.";

            }

          }

          else {

            if (param_1 == -0x7787ee7b) {

              return "Object was not found.";

            }

            if (param_1 == -0x7787ee7a) {

              return "The file name is missing from the DMUS_OBJECTDESC.";

            }

            if (param_1 == -0x7787ee00) {

              return "The file requested is not a valid file.";

            }

          }

        }

        else {

          if (param_1 == -0x7787edfe) {

            return 

            "Value is out of range, for instance the requested length is longer than the segment.";

          }

          if (param_1 == -0x7787edfd) {

            return "Segment initialization failed, most likely due to a critical memory situation.";

          }

          if (param_1 == -0x7787edfc) {

            return 

            "The DMUS_PMSG has already been sent to the performance object via IDirectMusicPerformance::SendPMsg()."

            ;

          }

          if (param_1 == -0x7787edfb) {

            return 

            "The DMUS_PMSG was either not allocated by the performance via IDirectMusicPerformance::AllocPMsg(), or it was already freed via IDirectMusicPerformance::FreePMsg()."

            ;

          }

          if (param_1 == -0x7787edfa) {

            return "The default system port could not be opened.";

          }

          if (param_1 == -0x7787edf9) {

            return 

            "A call to MIDIToMusic() or MusicToMIDI() resulted in an error because the requested conversion could not happen. This usually occurs when the provided DMUS_CHORD_KEY structure has an invalid chord or scale pattern."

            ;

          }

          if (param_1 == -0x7787edf0) {

            return 

            "DMUS_E_DESCEND_CHUNK_FAIL is returned when the end of the file  was reached before the desired chunk was found."

            ;

          }

        }

      }

      else {

        switch(param_1) {

        case -0x7787eded:

          return 

          "The activeX scripting engine for the script\'s language is not compatible with DirectMusic."

          ;

        case -0x7787edec:

          return "A varient was used that had a type that is not supported by DirectMusic.";

        case -0x7787edeb:

          return 

          "An error was encountered while parsing or executing the script. The pErrorInfo parameter (if supplied) was filled with information about the error."

          ;

        case -0x7787edea:

          return 

          "Loading of oleaut32.dll failed.  VBScript and other activeX scripting languages require use of oleaut32.dll.  On platforms where oleaut32.dll is not present, only the DirectMusicScript language, which doesn\'t require oleaut32.dll can be used."

          ;

        case -0x7787ede9:

          return 

          "An error occured while parsing a script loaded using LoadScript.  The script that was loaded contains an error."

          ;

        case -0x7787ede8:

          return "The script file is invalid.";

        case -0x7787ede7:

          return "The file contains an invalid script track.";

        case -0x7787ede6:

          return "The script does not contain a variable with the specified name.";

        case -0x7787ede5:

          return "The script does not contain a routine with the specified name.";

        case -0x7787ede4:

          return "Scripts variables for content referenced or embedded in a script cannot be set.";

        case -0x7787ede3:

          return 

          "Attempt was made to set a script\'s variable by reference to a value that was not an object type."

          ;

        case -0x7787ede2:

          return 

          "Attempt was made to set a script\'s variable by value to an object that does not support a default value property."

          ;

        case -0x7787ede0:

          return "The file contains an invalid segment trigger track.";

        case -0x7787eddf:

          return "The file contains an invalid lyrics track.";

        case -0x7787edde:

          return "The file contains an invalid parameter control track.";

        }

      }

    }

    else if (param_1 < -0x3788f447) {

      if (param_1 == -0x3788f448) {

        return "Out of memory";

      }

      switch(param_1) {

      case -0x7787eddc:

        return 

        "A script routine written in AudioVBScript failed because an invalid operation occurred.  For example, adding the number 3 to a segment object would produce this error.  So would attempting to call a routine that doesn\'t exist."

        ;

      case -0x7787eddb:

        return 

        "A script routine written in AudioVBScript failed because a function outside of a script failed to complete. For example, a call to PlaySegment that fails to play because of low memory would return this error."

        ;

      case -0x7787edda:

        return 

        "The Performance has set up some PChannels using the AssignPChannel command, which makes it not capable of supporting audio paths."

        ;

      case -0x7787edd9:

        return 

        "This is the inverse of the previous error. The Performance has set up some audio paths, which makes is incompatible with the calls to allocate pchannels, etc. "

        ;

      case -0x7787edd8:

        return 

        "A segment or song was asked for its embedded audio path configuration, but there isn\'t any. "

        ;

      case -0x7787edd7:

        return "An audiopath is inactive, perhaps because closedown was called.";

      case -0x7787edd6:

        return "An audiopath failed to create because a requested buffer could not be created.";

      case -0x7787edd5:

        return "An audiopath could not be used for playback because it lacked port assignments.";

      case -0x7787edd4:

        return "Attempt was made to play segment in audiopath mode and there was no audiopath.";

      case -0x7787edd3:

        return "Invalid data was found in a RIFF file chunk.";

      case -0x7787edd2:

        return 

        "Attempt was made to create an audiopath that sends to a global effects buffer which did not exist."

        ;

      case -0x7787edd1:

        return "The file does not contain a valid container object.";

      }

    }

    else {

      switch(param_1) {

      case -0x3788f447:

        return "A NULL pointer was passed as a parameter";

      case -0x3788f446:

        return "The Device Index passed in is invalid";

      case -0x3788f445:

        return "DirectDraw has not been created";

      case -0x3788f444:

        return "Direct3D has not been created";

      case -0x3788f443:

        return "Direct3D device has not been created";

      case -0x3788f442:

        return "Primary surface has not been created";

      case -0x3788f441:

        return "Z buffer has not been created";

      case -0x3788f440:

        return "Backbuffer has not been created";

      case -0x3788f43f:

        return "Failed to update caps database after changing display mode";

      case -0x3788f43e:

        return "Could not create Z buffer";

      case -0x3788f43d:

        return "Display mode is not valid";

      case -0x3788f43c:

        return "One or more of the parameters passed is invalid";

      case -0x3788f43b:

        return "D3DX failed to initialize itself";

      case -0x3788f43a:

        return "D3DX failed to start up";

      case -0x3788f439:

        return "D3DXInitialize() must be called first";

      case -0x3788f438:

        return "D3DX is not initialized yet";

      case -0x3788f437:

        return "Failed to render text to the surface";

      case -0x3788f436:

        return "Bad D3DX context";

      case -0x3788f435:

        return "The requested device capabilities are not supported";

      }

    }

  }

  else if (param_1 < 1) {

    if (param_1 == 0) {

      return "The function completed successfully";

    }

    switch(param_1) {

    case -0x3788f433:

      return "The image file loading library error";

    case -0x3788f432:

      return "Could not obtain device caps";

    case -0x3788f431:

      return "Resize does not work for full-screen";

    case -0x3788f430:

      return "Resize does not work for non-windowed contexts";

    case -0x3788f42f:

      return "Front buffer already exists";

    case -0x3788f42e:

      return "The app is using the primary in full-screen mode";

    case -0x3788f42d:

      return "Could not get device context";

    case -0x3788f42c:

      return "Could not bitBlt";

    case -0x3788f42b:

      return "There is no surface backing up this texture";

    case -0x3788f42a:

      return "There is no such miplevel for this surface";

    case -0x3788f429:

      return "The surface is not paletted";

    case -0x3788f428:

      return "An error occured while enumerating surface formats";

    case -0x3788f427:

      return "D3DX only supports color depths of 16 bit or greater";

    case -0x3788f426:

      return "The file format is invalid";

    case -0x3788f425:

      return "No suitable match found";

    }

  }

  else if (param_1 < 0x40004) {

    if (param_1 == 0x40003) {

      return "End of stream. Sample not updated.";

    }

    switch(param_1) {

    case 1:

      return "Call successful, but returned FALSE";

    case 2:

      goto switchD_006b9cfb_caseD_2;

    case 3:

switchD_006b81cc_caseD_80070003:

      return "The system cannot find the path specified.";

    case 4:

switchD_006b81cc_caseD_80070004:

      return "The system cannot open the file.";

    case 5:

      return "Access is denied.";

    case 6:

      return "The handle is invalid.";

    case 8:

switchD_006b81cc_caseD_80070008:

      return "Not enough storage is available to process this command.";

    case 9:

switchD_006b81cc_caseD_80070009:

      return "The storage control block address is invalid.";

    case 10:

switchD_006b81cc_caseD_8007000a:

      return "The environment is incorrect.";

    case 0xb:

switchD_006b81cc_caseD_8007000b:

      return "An attempt was made to load a program with an incorrect format.";

    case 0xe:

      return "The system cannot find the drive specified.";

    }

  }

  else if (param_1 < 0x4028d) {

    if (param_1 == 0x4028c) {

      return 

      "The audio stream did not contain sufficient information to determine the contents of each channel."

      ;

    }

    if (param_1 < 0x40259) {

      if (param_1 == 0x40258) {

        return "Cannot play back the audio stream: no audio hardware is available.";

      }

      if (param_1 < 0x40246) {

        if (param_1 == 0x40245) {

          return "The file contained some property settings that were not used.";

        }

        if (param_1 == 0x40103) {

          return "The end of the list has been reached.";

        }

        if (param_1 == 0x4022d) {

          return "An attempt to add a filter with a duplicate name succeeded with a modified name.";

        }

        if (param_1 == 0x40237) {

          return "The state transition has not completed.";

        }

        if (param_1 == 0x40242) {

          return "Some of the streams in this movie are in an unsupported format.";

        }

      }

      else {

        if (param_1 == 0x40246) {

          return "Some connections have failed and have been deferred.";

        }

        if (param_1 == 0x40250) {

          return "The resource specified is no longer needed.";

        }

        if (param_1 == 0x40254) {

          return 

          "A connection could not be made with the media type in the persistent graph, but has been made with a negotiated media type."

          ;

        }

        if (param_1 == 0x40257) goto switchD_006b7cfe_caseD_80040255;

      }

    }

    else if (param_1 < 0x40269) {

      if (param_1 == 0x40268) {

        return "The graph can\'t be cued because of lack of or corrupt data.";

      }

      if (param_1 == 0x4025a) goto LAB_006b9e86;

      if (param_1 == 0x40260) {

        return "The value returned had to be estimated.  It\'s accuracy can not be guaranteed.";

      }

      if (param_1 == 0x40263) {

        return "This success code is reserved for internal purposes within ActiveMovie.";

      }

      if (param_1 == 0x40267) {

        return "The stream has been turned off.";

      }

    }

    else {

      if (param_1 == 0x40270) {

        return "The stop time for the sample was not set.";

      }

      if (param_1 == 0x4027e) {

        return 

        "There was no preview pin available, so the capture pin output is being split to provide both capture and preview."

        ;

      }

      if (param_1 == 0x40280) {

        return 

        "The current title was not a sequential set of chapters (PGC), and the returned timing information might not be continuous."

        ;

      }

    }

  }

  else if (param_1 < 0x8781202) {

    if (param_1 == 0x8781201) {

      return 

      "Return value from IDirectMusicTool::ProcessPMsg() which indicates to the performance that it should free the PMsg automatically."

      ;

    }

    if (param_1 < 0x8760870) {

      if (param_1 == 0x876086f) {

        return "The call succeeded but there won\'t be any mipmaps generated";

      }

      if (param_1 == 0x4028d) {

        return "The seek into the movie was not frame accurate.";

      }

      if (param_1 == 0x150005) {

        return "Full duplex";

      }

      if (param_1 == 0x15000a) {

        return "Half duplex";

      }

      if (param_1 == 0x150010) {

        return "Pending";

      }

    }

    else {

      if (param_1 == 0x878000a) {

        return "The call succeeded, but we had to substitute the 3D algorithm";

      }

      if (param_1 == 0x8781091) {

        return 

        "The object could only load partially. This can happen if some components are not registered properly, such as embedded tracks and tools. This can also happen if some content is missing. For example, if a segment uses a DLS collection that is not in the loader\'s current search directory."

        ;

      }

      if (param_1 == 0x8781092) {

        return 

        "Return value from IDirectMusicBand::Download() which indicates that some of the instruments safely downloaded, but others failed. This usually occurs when some instruments are on PChannels not supported by the performance or port."

        ;

      }

      if (param_1 == 0x8781200) {

        return 

        "Return value from IDirectMusicTool::ProcessPMsg() which indicates to the performance that it should cue the PMsg again automatically."

        ;

      }

    }

  }

  else if (param_1 < 0x8781214) {

    if (param_1 == 0x8781213) {

      return 

      "Returned from IDirectMusicPerformance::MIDIToMusic(),  and IDirectMusicPerformance::MusicToMIDI(), this indicates  that the note conversion generated a note value that is below 0,  so it has been bumped up one or more octaves to be in the proper MIDI range of 0 through 127.  Note that this is valid for MIDIToMusic() when using play modes DMUS_PLAYMODE_FIXEDTOCHORD and DMUS_PLAYMODE_FIXEDTOKEY, both of which store MIDI values in wMusicValue. With MusicToMIDI(), it is valid for all play modes. Ofcourse, DMUS_PLAYMODE_FIXED will never return this success code."

      ;

    }

    if (param_1 == 0x8781202) {

      return 

      "Return value from IDirectMusicTrack::Play() which indicates to the segment that the track has no more data after mtEnd."

      ;

    }

    if (param_1 == 0x8781210) {

      return "Returned string has been truncated to fit the buffer size.";

    }

    if (param_1 == 0x8781211) {

      return 

      "Returned from IDirectMusicGraph::StampPMsg(), this indicates that the PMsg is already stamped with the last tool in the graph. The returned PMsg\'s tool pointer is now NULL."

      ;

    }

    if (param_1 == 0x8781212) {

      return 

      "Returned from IDirectMusicPerformance::MusicToMIDI(), this indicates  that no note has been calculated because the music value has the note  at a position higher than the top note of the chord. This applies only to DMUS_PLAYMODE_NORMALCHORD play mode. This success code indicates that the caller should not do anything with the note. It is not meant to be played against this chord."

      ;

    }

  }

  else {

    if (param_1 == 0x8781214) {

      return 

      "Returned from IDirectMusicPerformance::MIDIToMusic(),  and IDirectMusicPerformance::MusicToMIDI(), this indicates  that the note conversion generated a note value that is above 127, so it has been bumped down one or more octaves to be in the proper MIDI range of 0 through 127.  Note that this is valid for MIDIToMusic() when using play modes DMUS_PLAYMODE_FIXEDTOCHORD and DMUS_PLAYMODE_FIXEDTOKEY, both of which store MIDI values in wMusicValue. With MusicToMIDI(), it is valid for all play modes. Ofcourse, DMUS_PLAYMODE_FIXED will never return this success code."

      ;

    }

    if (param_1 == 0x8781215) {

      return 

      "Although the audio output from the port will be routed to the same device as the given DirectSound buffer, buffer controls such as pan and volume will not affect the output."

      ;

    }

    if (param_1 == 0x8781216) {

      return 

      "The requested operation was not performed because during CollectGarbage the loader determined that the object had been released."

      ;

    }

  }

  return "n/a";

}
