# Raw capture: FUN_0040afb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040afb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0040afb0` |
| **Canonical name** | `FUN_0040afb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0040afb0(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x34)) {
    piVar2 = *(int **)(param_1 + 0x30);
    do {
      if (*piVar2 == param_3) {
        *param_2 = (*(int **)(param_1 + 0x30))[iVar1 * 2 + 1];
        return;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 2;
    } while (iVar1 < *(int *)(param_1 + 0x34));
  }
  *param_2 = 0;
  return;
}
```

---

## MEGA-028 live re-verify (2026-08-05) — APPEND ONLY

| Field | Value |
|---|---|
| **Agent** | OWN-ONLY dual **MEGA-028** |
| **Tools** | `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_callers` + `get_function_xrefs` + `get_assembly_context` |
| **Forbidden avoided** | no `disassemble_bytes`; no Launcher; no parent ledgers; no other VAs |
| **Live decompile** | **≡** 2026-07-23 raw CF (byte-identical pseudocode shape) |
| **Body** | `0x0040afb0`–`0x0040afed` inclusive (**62 B** / `0x3E`); next function `FUN_0040aff0` @ `0x0040aff0` after `CC` pad region not claimed |
| **ABI sealed** | **ECX** = host; stack `void **out`, `int key`; **EAX** = `out`; **`RET 8`** (`C2 08 00`) both exits |
| **Layout sealed** | host **`+0x30`** = base of `{int key; void* value}` pairs (stride **8**); host **`+0x34`** = signed count |
| **Algorithm** | linear scan; on match `*out = pair[i].value` and return; else `*out = 0` |
| **Callees** | **none** (leaf) |
| **Callers (7 functions / 13 UNCONDITIONAL_CALL sites)** | `FUN_00925820` (soft-cast / interaction), `FUN_004ea350` (GetObjectsInArea ×3), `FUN_005d9ea0` (Drive contact prep keys 3/4), `FUN_005da0a0` (Contact ×2), `FUN_005911b0` @ `0x00593160` (key 3), `FUN_00642b70` (key 1), `FUN_00932c80` (key 1); plus sites `0x005dd718` / `0x005dd80d` (key 1) |
| **Call-site pattern** | typical: `push key; lea out; push out; mov ecx, host; call 0040afb0; mov reg, [eax]` — host often from hit/material payload **`+0x20`** |
| **Keys observed** | **1** (soft-cast / area / physics), **3** and **4** (collision material pair-list) |
| **Proposed name** | `Host_LookupObjectByKey_PairTable30_Inferred` (retire `Named_CalleeOf_Named_VOG_DEBUG_STOP_0040afb0`) |
| **System** | interaction-activation (shared host pair-table leaf; also drive/collision consumers) |
| **Terminal** | **false** (no runtime Confirmed) |

### Live disassembly (authoritative)

```
0040afb0  MOV  EDX, dword ptr [ECX + 0x34]   ; count
0040afb3  PUSH ESI
0040afb4  XOR  EAX, EAX                       ; i = 0
0040afb6  TEST EDX, EDX
0040afb8  PUSH EDI
0040afb9  JLE  0040afd2                      ; miss if count <= 0
0040afbb  MOV  ESI, dword ptr [ECX + 0x30]   ; table base
0040afbe  MOV  EDI, dword ptr [ESP + 0x10]   ; key (stack after 2 pushes)
0040afc2  MOV  ECX, ESI
0040afc4  CMP  dword ptr [ECX], EDI          ; pair.key == key?
0040afc6  JZ   0040afe1                      ; hit
0040afc8  ADD  EAX, 0x1
0040afcb  ADD  ECX, 0x8                      ; next pair
0040afce  CMP  EAX, EDX
0040afd0  JL   0040afc4
0040afd2  MOV  EAX, dword ptr [ESP + 0xc]    ; out
0040afd6  POP  EDI
0040afd7  MOV  dword ptr [EAX], 0x0          ; *out = 0
0040afdd  POP  ESI
0040afde  RET  0x8
0040afe1  MOV  ECX, dword ptr [ESI+EAX*8+4]  ; value
0040afe5  MOV  EAX, dword ptr [ESP + 0xc]    ; out
0040afe9  POP  EDI
0040afea  MOV  dword ptr [EAX], ECX          ; *out = value
0040afec  POP  ESI
0040afed  RET  0x8
```

### Live bytes (`read_memory` 64 B @ entry)

```
8b 51 34 56 33 c0 85 d2 57 7e 17 8b 71 30 8b 7c 24 10 8b ce 39 39 74 19
83 c0 01 83 c1 08 3b c2 7c f2 8b 44 24 0c 5f c7 00 00 00 00 00 5e c2 08 00
8b 4c c6 04 8b 44 24 0c 5f 89 08 5e c2 08 00
```

### Soft-cast parent call site (evidence only — not OWN)

`FUN_00925820` @ `0x00925c8f` (partition parent dual context):

```
; hit-list entry non-null at +0x20 → nested host at [eax+0x20]
PUSH 1
LEA  EDX, [ESP+0x1c]
PUSH EDX
MOV  ECX, EAX   ; host
CALL 0040afb0
MOV  EDI, [EAX]  ; *out object*
```

### Completeness snapshot (analyze_function_complete)

| Item | Value |
|---|---|
| Classification | leaf |
| has_custom_name | false |
| callees | [] |
| xref_count | 13 |
| return_type_warning | decompiler void — **EAX = out** sealed via assembly |
