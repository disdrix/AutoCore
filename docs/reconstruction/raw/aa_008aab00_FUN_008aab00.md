# Raw capture: FUN_008aab00

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aab00` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008aab00` |
| **Canonical name** | `FUN_008aab00` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __thiscall FUN_008aab00(char *param_1,int *param_2)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  undefined1 *puVar6;
  int iVar7;
  bool bVar8;
  char *pcVar9;
  int local_204c;
  char local_2040 [64];
  byte local_2000 [4096];
  byte local_1000 [6];
  byte local_ffa [4086];
  undefined4 uStack_4;
  
  uStack_4 = 0x8aab0a;
  if ((param_2 != (int *)0x0) && (param_1 != (char *)0x0)) {
    FUN_007a69d0();
    iVar7 = -(int)param_1;
    do {
      cVar2 = *param_1;
      param_1[(int)(local_1000 + iVar7)] = cVar2;
      param_1 = param_1 + 1;
    } while (cVar2 != '\0');
    iVar7 = 0;
    local_204c = 0;
    if (local_1000[0] != 0) {
LAB_008aab70:
      pbVar5 = local_1000 + iVar7;
      if ((local_1000[iVar7] == 0x5b) && (local_1000[iVar7 + 1] == 0x24)) {
        if (0 < local_204c) {
          iVar3 = *param_2;
          local_2000[local_204c] = 0;
          (**(code **)(iVar3 + 0x250))(local_2000);
          local_204c = 0;
        }
        iVar3 = _strnicmp((char *)pbVar5,"[$imp]",6);
        if (iVar3 == 0) {
          (**(code **)(*param_2 + 0x230))(0xffff2d00);
          iVar7 = iVar7 + 6;
        }
        else {
          iVar3 = _strnicmp((char *)pbVar5,"[$/imp]",7);
          if (iVar3 == 0) {
            (**(code **)(*param_2 + 0x23c))();
            iVar7 = iVar7 + 7;
          }
          else {
            iVar3 = _strnicmp((char *)pbVar5,"[$npc]",6);
            if (iVar3 == 0) {
              (**(code **)(*param_2 + 0x230))(0xff256ec8);
              iVar7 = iVar7 + 6;
            }
            else {
              iVar3 = _strnicmp((char *)pbVar5,"[$/npc]",7);
              if (iVar3 == 0) {
                (**(code **)(*param_2 + 0x23c))();
                iVar7 = iVar7 + 7;
              }
              else {
                iVar3 = _strnicmp((char *)pbVar5,"[$inst]",7);
                if (iVar3 == 0) {
                  (**(code **)(*param_2 + 0x230))(0xffc5c025);
                  iVar7 = iVar7 + 7;
                }
                else {
                  iVar3 = _strnicmp((char *)pbVar5,"[$/inst]",8);
                  if (iVar3 == 0) {
                    (**(code **)(*param_2 + 0x23c))();
                    iVar7 = iVar7 + 8;
                  }
                  else {
                    iVar3 = _strnicmp((char *)pbVar5,"[$loc]",6);
                    if (iVar3 == 0) {
                      (**(code **)(*param_2 + 0x230))(0xfff59623);
                      iVar7 = iVar7 + 6;
                    }
                    else {
                      iVar3 = _strnicmp((char *)pbVar5,"[$/loc]",7);
                      if (iVar3 == 0) {
                        (**(code **)(*param_2 + 0x23c))();
                        iVar7 = iVar7 + 7;
                      }
                      else {
                        iVar3 = _strnicmp((char *)pbVar5,"[$emote]",8);
                        if (iVar3 == 0) {
                          (**(code **)(*param_2 + 0x230))(0xff29b525);
                          iVar7 = iVar7 + 8;
                        }
                        else {
                          iVar3 = _strnicmp((char *)pbVar5,"[$/emote]",9);
                          if (iVar3 == 0) {
                            (**(code **)(*param_2 + 0x23c))();
                            iVar7 = iVar7 + 9;
                          }
                          else {
                            iVar3 = _strnicmp((char *)pbVar5,"[$pause]",8);
                            if (iVar3 == 0) {
                              (**(code **)(*param_2 + 0x254))(0x14);
                              iVar7 = iVar7 + 8;
                            }
                            else {
                              iVar3 = _strnicmp((char *)pbVar5,"[$key]",6);
                              if (iVar3 != 0) {
                                local_2000[local_204c] = *pbVar5;
                                goto LAB_008aaf20;
                              }
                              pbVar5 = local_ffa + iVar7;
                              local_204c = 0;
                              bVar1 = *pbVar5;
                              iVar7 = iVar7 + 6;
                              while (bVar1 != 0) {
                                if (((bVar1 == 0x5b) && (local_1000[iVar7 + 1] == 0x24)) &&
                                   (iVar3 = _strnicmp((char *)pbVar5,"[$/key]",7), iVar3 == 0)) {
                                  iVar7 = iVar7 + 7;
                                  local_2000[local_204c] = 0;
                                  pbVar4 = (byte *)FUN_007a6de0("Free Look",0xffffffff);
                                  pbVar5 = local_2000;
                                  goto LAB_008aadf7;
                                }
                                local_2000[local_204c] = *pbVar5;
                                local_204c = local_204c + 1;
                                pbVar5 = local_1000 + iVar7 + 1;
                                iVar7 = iVar7 + 1;
                                bVar1 = *pbVar5;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else {
        local_2000[local_204c] = local_1000[iVar7];
LAB_008aaf20:
        local_204c = local_204c + 1;
        iVar7 = iVar7 + 1;
      }
      goto LAB_008aaf23;
    }
  }
  return;
  while( true ) {
    bVar1 = pbVar5[1];
    bVar8 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_008aae1b;
    pbVar5 = pbVar5 + 2;
    pbVar4 = pbVar4 + 2;
    if (bVar1 == 0) break;
LAB_008aadf7:
    bVar1 = *pbVar5;
    bVar8 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_008aae1b:
      iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
      goto LAB_008aae20;
    }
    if (bVar1 == 0) break;
  }
  iVar3 = 0;
LAB_008aae20:
  if (iVar3 == 0) {
    pbVar5 = (byte *)FUN_007f5120();
    pcVar9 = "%s";
  }
  else {
    pbVar5 = local_2000;
    do {
      bVar1 = *pbVar5;
      pbVar5 = pbVar5 + 1;
    } while (bVar1 != 0);
    if ((pbVar5 != local_2000 + 1) && ((uint)((int)pbVar5 - (int)(local_2000 + 1)) < 0x22)) {
      FUN_007a69d0();
      cVar2 = '\0';
      puVar6 = &DAT_00d1bbf5;
      do {
        pcVar9 = (char *)FUN_007a6de0(puVar6,0xffffffff);
        iVar3 = _stricmp((char *)local_2000,pcVar9);
        if (iVar3 == 0) goto LAB_008aaea5;
        puVar6 = puVar6 + 0x34;
        cVar2 = cVar2 + '\x01';
      } while ((int)puVar6 < 0xd1d455);
    }
    cVar2 = '\0';
LAB_008aaea5:
    cVar2 = FUN_007f9160(cVar2,0);
    if (cVar2 != '\0') goto LAB_008aaedb;
    pbVar5 = local_2000;
    pcVar9 = "<%s>";
  }
  sprintf(local_2040,pcVar9,pbVar5);
LAB_008aaedb:
  (**(code **)(*param_2 + 0x250))(local_2040);
  local_204c = 0;
LAB_008aaf23:
  if (local_1000[iVar7] == 0) {
    if (local_204c == 0) {
      return;
    }
    iVar7 = *param_2;
    local_2000[local_204c] = 0;
    (**(code **)(iVar7 + 0x250))(local_2000);
    return;
  }
  goto LAB_008aab70;
}
```

---

## WQ7R-C re-verify (2026-08-04)

| Field | Value |
|---|---|
| **Agent** | WQ7R-C OWN-ONLY dual |
| **Tools** | `batch_decompile` / `analyze_function_complete` / `read_memory` / `get_function_xrefs` / `get_assembly_context` / `get_function_by_address` |
| **No** | `disassemble_bytes`; Launcher; parent ledgers |
| **Live ≡ scaffold raw** | **Yes** (markup tag matrix, colors, key path, vtbl ordinals) |
| **Body** | `0x008aab00`–`0x008aaf58` exclusive (**1112 B** / `0x458`) |
| **Epilogue bytes** @ `0x008aaf50` | `5F 5E 5D 81 C4 4C 20 00 00 C3` = `pop edi; pop esi; pop ebp; add esp,0x204c; ret` |
| **Entry bytes** @ `0x008aab00` | `B8 4C 20 00 00` = `mov eax,0x204c` then `__chkstk`; `mov esi,ecx` (markup); stack arg → richtext widget |
| **ABI** | **ECX = markup C-string**; **stack[0] = richtext widget*** (`int*` vtbl host); callers `ADD ESP,4` |
| **Classification** | worker |
| **Xrefs (6)** | `FUN_008aaf60`@`008aaff3`, `FUN_008a3510`@`008a3c35`+`008a3f80`, `FUN_008cc5a0`@`008cc5c0`, `FUN_008cdae0`@`008cdf9b`, `FUN_008dbe10`@`008dbf2c` |
| **Callees** | `FUN_007a69d0`, `__chkstk`, `FUN_007a6de0`, `FUN_007f5120`, `FUN_007f9160`, `_strnicmp`, `_stricmp`, `sprintf` |
| **Name (Inferred)** | `MissionDialog_ParseMarkupToRichText_Inferred` |

### Markup → chrome matrix (sealed)

| Tag open | Tag close | Action | Constant |
|---|---|---|---|
| `[$imp]` | `[$/imp]` | vtbl+0x230 SetColor / +0x23c PopColor | `0xFFFF2D00` ARGB(255,255,45,0) |
| `[$npc]` | `[$/npc]` | same | `0xFF256EC8` ARGB(255,37,110,200) |
| `[$inst]` | `[$/inst]` | same | `0xFFC5C025` ARGB(255,197,192,37) |
| `[$loc]` | `[$/loc]` | same | `0xFFF59623` ARGB(255,245,150,35) |
| `[$emote]` | `[$/emote]` | same | `0xFF29B525` ARGB(255,41,181,37) |
| `[$pause]` | — | vtbl+0x254 Pause | `0x14` (20) |
| `[$key]`…`[$/key]` | pair | keybind resolve → AppendText | see key path |

Plain runs and flush: vtbl+**0x250** AppendText on accumulated `local_2000` buffer (4 KiB).

### Keybind path (sealed CF)

1. Capture text between `[$key]` and `[$/key]` into buffer.
2. Localize `"Free Look"` via `FUN_007a6de0`; if equal → `FUN_007f5120()` display string + format `"%s"`.
3. Else if len in (0, 0x22): scan `DAT_00d1bbf5` stride **0x34** until `< 0x00d1d455` (**120** slots); match via localized name; on hit `FUN_007f9160(index, 0)` — non-zero skips sprintf (display already ready).
4. Miss → `sprintf(local_2040, "<%s>", rawKey)`.
5. Append result via vtbl+0x250.

Static `read_memory` @ `DAT_00d1bbf5`: all zero (runtime-filled key table).

### Vtbl ordinals on richtext widget (role-Inferred)

| Offset | Role |
|---|---|
| +0x230 | SetColor(ARGB) |
| +0x23c | PopColor / restore |
| +0x250 | AppendText(cstr) |
| +0x254 | Pause/delay(ticks) |

