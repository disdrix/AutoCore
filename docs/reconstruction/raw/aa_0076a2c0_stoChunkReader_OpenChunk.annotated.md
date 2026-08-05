# Annotated low-level: stoChunkReader_OpenChunk

| Field | Value |
|---|---|
| Stable ID | `aa_0076a2c0` |
| VA | `0x0076a2c0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0076a2c0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* stoChunkReader::OpenChunk()  [arda2\storage\stoChunk.cpp:~0x1d4]
   Reads the next chunk header and pushes it on the reader's chunk ring (this+0x4034..0x4040).
   Handles both binary (16-byte {tag,size,version,reserved} header) and text mode (parses CHUNK
   "TAG" version { tokens; errors "Expected \"CHUNK\" keyword", "Chunk tag not FOURCC"). this+0x4044
   selects text mode; this+0x402c is the sticky error flag. */

undefined4 __fastcall stoChunkReader_OpenChunk(int param_1)

{
  uint *puVar1;
  char cVar2;
  char **ppcVar3;
  bool bVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  char ***pppcVar8;
  undefined4 uVar9;
  char *pcVar10;
  char local_41;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  undefined1 local_34 [8];
  int local_2c;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [4];
  char **local_24 [4];
  int local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b0b38;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 0x4044) == 0) {
    ExceptionList = &local_c;
    uVar6 = FUN_004368b0();
    puVar1 = (uint *)(param_1 + 0x402c);
    *puVar1 = *puVar1 | uVar6;
    if (-1 < (int)*puVar1) {
      local_2c = *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x18) + local_38;
LAB_0076a8d6:
      FUN_00436340();
      ExceptionList = local_c;
      return 0;
    }
  }
  else {
    ExceptionList = &local_c;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);
    local_4 = 0;
    if (*(int *)(param_1 + 0x402c) < 0) {
      uVar6 = 0xffffffff;
    }
    else {
      if (*(int *)(param_1 + 0x4060) == 0) {
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::resize
                  (local_28,0);
        bVar5 = false;
        local_41 = '\"';
        do {
          bVar4 = false;
LAB_0076a3e0:
          do {
            if ((*(int *)(param_1 + 0x20) < *(int *)(param_1 + 0x18) + 1) &&
               ((iVar7 = FUN_00435df0(*(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x18)),
                iVar7 < 0 || (*(int *)(param_1 + 0x20) < 1)))) {
              if (bVar5) goto LAB_0076a360;
              uVar6 = 0xffffffff;
              *(undefined4 *)(param_1 + 0x402c) = 0xffffffff;
              goto LAB_0076a496;
            }
            cVar2 = *(char *)(*(int *)(param_1 + 0x18) + param_1 + 0x2c);
            local_40 = CONCAT31(local_40._1_3_,cVar2);
            *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
            if (!bVar4) {
              if ((cVar2 == '\'') || (cVar2 == '\"')) {
                bVar4 = true;
                local_41 = cVar2;
              }
              else {
                iVar7 = isspace((int)cVar2);
                if (iVar7 != 0) {
                  if (bVar5) goto LAB_0076a360;
                  goto LAB_0076a3e0;
                }
              }
              bVar5 = true;
              std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
              operator+=(local_28,(char)local_40);
              goto LAB_0076a3e0;
            }
            std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
            operator+=(local_28,cVar2);
          } while (cVar2 != local_41);
        } while( true );
      }
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=
                (local_28,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                           *)(param_1 + 0x404c));
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=
                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 (param_1 + 0x404c),"");
LAB_0076a360:
      bVar5 = std::operator==<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        (local_28,"}");
      if (bVar5) {
        vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp",0x2a0,3,
                       "Attempt to read past end of chunk. Ignoring reads until chunk exit");
        *(undefined4 *)(param_1 + 0x402c) = 0xffffffff;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=
                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   (param_1 + 0x404c),local_28);
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=
                  (local_28,"");
        uVar6 = 0xffffffff;
      }
      else {
        uVar6 = 0;
      }
    }
LAB_0076a496:
    puVar1 = (uint *)(param_1 + 0x402c);
    *puVar1 = *puVar1 | uVar6;
    if ((int)*puVar1 < 0) {
      pcVar10 = "Error finding chunk token";
      uVar9 = 0x1d4;
    }
    else {
      pppcVar8 = (char ***)local_24[0];
      if (local_10 < 0x10) {
        pppcVar8 = local_24;
      }
      iVar7 = _stricmp((char *)pppcVar8,"CHUNK");
      if (iVar7 != 0) {
        *(undefined4 *)(param_1 + 0x402c) = 0xffffffff;
        if (local_10 < 0x10) {
          local_24[0] = (char **)local_24;
        }
        uVar9 = FUN_0076cec0(&local_40,"Expected \"CHUNK\" keyword but got \"%s\"",local_24[0]);
        vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp",0x1d9,3,uVar9);
        local_4 = 0xffffffff;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);
        ExceptionList = local_c;
        return 0xffffffff;
      }
      uVar6 = FUN_00769b70(param_1);
      puVar1 = (uint *)(param_1 + 0x402c);
      *puVar1 = *puVar1 | uVar6;
      if ((int)*puVar1 < 0) {
        if (local_10 < 0x10) {
          local_24[0] = (char **)local_24;
        }
        uVar9 = FUN_0076cec0(&local_40,"Invalid chunk tag: \"%s\"",local_24[0]);
        vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp",0x1dd,3,uVar9);
        local_4 = 0xffffffff;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);
        ExceptionList = local_c;
        return 0xffffffff;
      }
      if (local_14 != 4) {
        *(undefined4 *)(param_1 + 0x402c) = 0xffffffff;
        if (local_10 < 0x10) {
          local_24[0] = (char **)local_24;
        }
        uVar9 = FUN_0076cec0(&local_40,"Chunk tag not FOURCC: \"%s\"",local_24[0]);
        vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp",0x1e2,3,uVar9);
        local_4 = 0xffffffff;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);
        ExceptionList = local_c;
        return 0xffffffff;
      }
      pppcVar8 = (char ***)local_24[0];
      if (local_10 < 0x10) {
        pppcVar8 = local_24;
      }
      ppcVar3 = *pppcVar8;
      local_40 = CONCAT13((char)ppcVar3,
                          CONCAT12((char)((uint)ppcVar3 >> 8),
                                   CONCAT11((char)((uint)ppcVar3 >> 0x10),
                                            (char)((uint)ppcVar3 >> 0x18))));
      local_3c = local_40;
      if (*(int *)(param_1 + 0x4044) == 0) {
        uVar6 = FUN_00437050(local_34);
      }
      else {
        uVar6 = FUN_007689e0(local_34);
      }
      puVar1 = (uint *)(param_1 + 0x402c);
      *puVar1 = *puVar1 | uVar6;
      if (-1 < (int)*puVar1) {
        if (*(int *)(param_1 + 0x4060) == 0) {
          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::resize
                    (local_28,0);
          bVar5 = false;
          local_41 = '\"';
          do {
            bVar4 = false;
LAB_0076a755:
            do {
              if ((*(int *)(param_1 + 0x20) < *(int *)(param_1 + 0x18) + 1) &&
                 ((iVar7 = FUN_00435df0(*(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x18)),
                  iVar7 < 0 || (*(int *)(param_1 + 0x20) < 1)))) {
                if (bVar5) goto LAB_0076a6d7;
                *(undefined4 *)(param_1 + 0x402c) = 0xffffffff;
                uVar6 = 0xffffffff;
                goto LAB_0076a810;
              }
              cVar2 = *(char *)(*(int *)(param_1 + 0x18) + param_1 + 0x2c);
              local_40 = CONCAT31(local_40._1_3_,cVar2);
              *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
              if (!bVar4) {
                if ((cVar2 == '\'') || (cVar2 == '\"')) {
                  bVar4 = true;
                  local_41 = cVar2;
                }
                else {
                  iVar7 = isspace((int)cVar2);
                  if (iVar7 != 0) {
                    if (bVar5) goto LAB_0076a6d7;
                    goto LAB_0076a755;
                  }
                }
                bVar5 = true;
                std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
                operator+=(local_28,(char)local_40);
                goto LAB_0076a755;
              }
              std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
              operator+=(local_28,cVar2);
            } while (cVar2 != local_41);
          } while( true );
        }
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=
                  (local_28,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                             *)(param_1 + 0x404c));
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=
                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   (param_1 + 0x404c),"");
LAB_0076a6d7:
        bVar5 = std::operator==<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                          (local_28,"}");
        if (bVar5) {
          vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp",0x2a0,3,
                         "Attempt to read past end of chunk. Ignoring reads until chunk exit");
          *(undefined4 *)(param_1 + 0x402c) = 0xffffffff;
          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
          operator=((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                    (param_1 + 0x404c),local_28);
          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
          operator=(local_28,"");
          uVar6 = 0xffffffff;
        }
        else {
          uVar6 = 0;
        }
LAB_0076a810:
        puVar1 = (uint *)(param_1 + 0x402c);
        *puVar1 = *puVar1 | uVar6;
        if ((int)*puVar1 < 0) {
          vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp",0x1f1,3,
                         "Error reading text block marker");
          local_4 = 0xffffffff;
          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
          ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);
          ExceptionList = local_c;
          return 0xffffffff;
        }
        bVar5 = std::operator!=<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                          (local_28,"{");
        if (bVar5) {
          *(undefined4 *)(param_1 + 0x402c) = 0xffffffff;
          if (local_10 < 0x10) {
            local_24[0] = (char **)local_24;
          }
          uVar9 = FUN_0076cec0(&local_40,"Expected block marker \"{\" but got: \"%s\"",local_24[0]);
          vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp",0x1f6,3,uVar9);
          local_4 = 0xffffffff;
          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
          ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);
          ExceptionList = local_c;
          return 0xffffffff;
        }
        local_4 = 0xffffffff;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);
        goto LAB_0076a8d6;
      }
      pcVar10 = "Could not read chunk version";
      uVar9 = 0x1ee;
    }
    vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp",uVar9,3,pcVar10);
    local_4 = 0xffffffff;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);
  }
  ExceptionList = local_c;
  return 0xffffffff;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
