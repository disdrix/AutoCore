# Review A (reconstruction fidelity): `aa_007a4480` NDError_Log

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a4480` |
| **VA** | `0x007a4480`–`0x007a44d0` |
| **Canonical name** | `NDError_Log` (Ghidra still `FUN_007a4480`; alias `Named_NDError_007a4480`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY dual A) |
| **Counterpart** | `reviews/B_aa_007a4480_NDError_Log.md` |
| **System** | libND / diagnostics (cross-cutting) |
| **Verdict** | **accept** — body sealed; enable-gate + varargs log path exact |

---

## 1. Purpose

**Conditional ND error logger** from `libND/NDError.cpp`. When `enable == 1` and `fmt != NULL`, formats a message with `_vsnprintf` into a **2048-byte** stack buffer and forwards it to `vog_LogMessage` with a fixed source path, **line `0x65` (101)**, and **level `3`**.

When `enable != 1` **or** `fmt == NULL`, the body is a **pure no-op** (still allocates/frees the 0x800 stack frame, then returns).

This is **not** a hard stop, `DebugBreak`, `MessageBox`, process exit, or exception throw. The ubiquitous caller string `"VOG_DEBUG_STOP"` is **argument data**, not this unit’s product name; most observed sites pass **`enable = 0`**, so those calls **never log**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007a4480_FUN_007a4480.md` |
| Annotated | `docs/reconstruction/raw/aa_007a4480_FUN_007a4480.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_007a4480.cpp` / `NDError_Log.cpp` |
| Function record | `docs/reconstruction/functions/aa_007a4480_FUN_007a4480.md` |
| Live Ghidra | `decompile_function` + `force_decompile` `0x007a4480` (identical) |
| | `analyze_function_complete` (callees, stack params) |
| | `get_function_pcode` basic (gate + CALL graph) |
| | `read_memory` body 128 B @ `0x007a4480`; path string @ `0x00a97124` |
| | `get_function_callers` sample (xref surface large; inventory **1921**) |
| Tools avoided | `disassemble_bytes` (policy) |

**Dual A/B decompile agreement (two reps):**

```
Rep1 decompile_function == Rep2 force_decompile
void FUN_007a4480(char param_1, char *param_2) {
  char local_800[2048];
  if ((param_1 == '\x01') && (param_2 != NULL)) {
    _vsnprintf(local_800, 0x800, param_2, &stack0x0000000c);
    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libND\\NDError.cpp", 0x65, 3, local_800);
  }
  return;
}
```

No third-rep needed (A/B byte+decompile consensus).

---

## 3. Signature

```c
// __cdecl, varargs; plain RET (caller cleans stack including extra args)
void __cdecl NDError_Log(char enable, const char *fmt, /* va_list from stack after fmt */ ...);
// Stack at entry (before SUB ESP,0x800):
//   [esp+4]  = enable (byte; compared to 1)
//   [esp+8]  = fmt
//   [esp+0xC] = first optional format argument (va start)
// Return: void (no EAX write; epilogue is ADD ESP,0x800; RET)
```

| Item | Evidence |
|---|---|
| Convention | Epilogue `ADD ESP,0x800; RET` — **not** `RET n` → **`__cdecl`** |
| Args | `Stack[0x4]:1` enable, `Stack[0x8]:4` fmt (`analyze_function_complete`) |
| Varargs | `_vsnprintf(..., &stack0x0000000c)` / P-code `PTRSUB ESP,0xc` as va list |
| Callees | `_vsnprintf` (IAT `0x009c64b4`), `vog_LogMessage` |
| Body range | Entry `007a4480`, `RET` @ `007a44d0` (~81 B; pad `CC` follows) |

---

## 4. Control flow (sealed)

```
SUB ESP, 0x800                          ; local_800[2048]
if (enable != 1) goto epilogue          ; CMP byte [enable], 1 / JNZ
if (fmt == NULL) goto epilogue          ; TEST fmt / JZ
_vsnprintf(local_800, 0x800, fmt, &va)  ; va = args after fmt
vog_LogMessage(path, 0x65, 3, local_800)
ADD ESP, 0x20                           ; clean both cdecl call arg blocks
epilogue:
ADD ESP, 0x800
RET
```

**Gate is exact equality to `1`.** Values `0`, `-1`/`0xFF`, `2`, etc. all skip logging.

---

## 5. Machine bytes (`read_memory` @ `0x007a4480`, 81 B body)

```
81 EC 00 08 00 00              SUB  ESP, 0x800
80 BC 24 04 08 00 00 01        CMP  BYTE PTR [ESP+0x804], 1   ; enable
75 3A                          JNZ  epilogue
8B 84 24 08 08 00 00           MOV  EAX, [ESP+0x808]          ; fmt
85 C0                          TEST EAX, EAX
74 2F                          JZ   epilogue
8D 8C 24 0C 08 00 00           LEA  ECX, [ESP+0x80C]          ; &va
51                             PUSH ECX
50                             PUSH EAX                       ; fmt
8D 54 24 08                    LEA  EDX, [ESP+8]              ; buffer
68 00 08 00 00                 PUSH 0x800
52                             PUSH EDX
FF 15 B4 64 9C 00              CALL DWORD PTR [_vsnprintf]    ; IAT 0x009c64b4
8D 44 24 10                    LEA  EAX, [ESP+0x10]           ; buffer (4 args still pushed)
50                             PUSH EAX                       ; msg
6A 03                          PUSH 3                         ; level
6A 65                          PUSH 0x65                      ; line 101
68 24 71 A9 00                 PUSH 0x00a97124                ; source path
E8 .. .. .. ..                 CALL vog_LogMessage
83 C4 20                       ADD  ESP, 0x20                 ; 8 dwords
81 C4 00 08 00 00              ADD  ESP, 0x800
C3                             RET
```

Hex (body):  
`81ec0008000080bc240408000001753a8b84240808000085c0742f8d8c240c08000051508d542408680008000052ff15b4649c008d442410506a036a65682471a900e8f9281f0083c42081c400080000c3`

---

## 6. Fixed log identity (`read_memory` @ `0x00a97124`)

```
"C:\vog\1_code\vog_14_117_branch\libND\NDError.cpp\0"
```

| Arg to `vog_LogMessage` | Value | Meaning |
|---|---|---|
| path | `0x00a97124` | `libND\NDError.cpp` (branch path baked in) |
| line | `0x65` = **101** | source line stamp |
| level | **3** | log severity constant (product label open) |
| message | `local_800` | formatted text |

---

## 7. Call-surface note (OWN-ONLY, not parent residual)

- Inventory / coverage: **~1921 xrefs** — shared diagnostic sink.
- Sample callers include hash/mission/creature/map paths; **typical pattern**:
  - `NDError_Log(0, "VOG_DEBUG_STOP")` — **no-op** in this binary
  - `NDError_Log(0, "HashError:...")` then often a second `VOG_DEBUG_STOP` — both no-ops when enable=0
  - Some sites pass **format strings with real printf args** and non-zero enable (actual log)
- **Do not** rename this unit to `VOG_DEBUG_STOP`; that string is call-site data.

---

## 8. Confidence

| Claim | Level |
|---|---|
| enable==1 && fmt!=NULL gate | **High** (bytes + pcode + dual decompile) |
| `_vsnprintf` count `0x800`, buffer 2048 | **High** |
| Fixed path / line 101 / level 3 | **High** (`read_memory` + push immediates) |
| cdecl + varargs | **High** (plain RET; va at +0xC) |
| void return / no hard-stop | **High** (no INT3/raise/exit in body) |
| `enable=0` sites are no-ops | **High** for body contract |
| Product English for level `3` | **Medium** (numeric only) |
| Exact CRT `_vsnprintf` vs MSVC variant | **High** as IAT symbol; CRT semantics deferred |

---

## 9. AutoCore impact

- Port may implement as no-op when matching retail **release** call sites that always pass `0`.
- Do **not** treat every `FUN_007a4480(0,"VOG_DEBUG_STOP")` as a crash barrier or assert that aborts.
- Real logging requires **`enable == 1`** plus non-null format (and `vog_LogMessage` backend).
- Keep buffer cap **2048** if mirroring format truncation behavior.
