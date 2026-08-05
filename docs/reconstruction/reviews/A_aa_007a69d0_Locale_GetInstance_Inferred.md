# Review A (reconstruction fidelity): `aa_007a69d0` Locale_GetInstance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a69d0` |
| **VA** | `0x007a69d0`–`0x007a6a29` (90 B) |
| **Canonical name** | `Locale_GetInstance_Inferred` (was `FUN_007a69d0`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (Meyers singleton getter) |
| **Counterpart** | `reviews/B_aa_007a69d0_Locale_GetInstance_Inferred.md` |
| **System** | locale / string-table (cross-cutting UI + chat) |
| **Verdict** | **accept** (body sealed; product class name Inferred) |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address`. Prefer decompile/read_memory (no `disassemble_bytes`). Sibling context only: ctor `FUN_007a6910` @ `0x007a6910`, dtor `FUN_007a6890` @ `0x007a6890`, locale-code leaf `FUN_007a6880` @ `0x007a6880` (returns `*(this+0x2c)`).

---

## 1. Purpose

**Meyers-style singleton getter** for the process-wide **locale / language string-table object** stored at **`DAT_00d1f660`**.

On first entry (once-flag `DAT_00d1f728` bit0 clear):

1. Set once-flag bit0.
2. Construct object via **`FUN_007a6910(&DAT_00d1f660)`** (vtable `PTR_FUN_00a96f88`, ring buffers, locale field `+0x2c = 0`).
3. Register **`atexit(LAB_009c30b0)`** — thunk: `MOV ECX, &DAT_00d1f660; JMP FUN_007a6890` (dtor frees string buffers / language packs).

Always returns **`&DAT_00d1f660`** in **EAX**.

This unit does **not** format messages, open PAK files, or take string arguments. Callers that look like `FUN_007a69d0("msg", …)` in reconstructed-exact are decompiler/parent-plate errors: args belong to **`FUN_007a6de0` (thiscall Localize)** or **`FUN_007fdfb0` (chat toast)** after the getter returns.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007a69d0_FUN_007a69d0.md` |
| Annotated | `docs/reconstruction/raw/aa_007a69d0_FUN_007a69d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_007a69d0.cpp` |
| Function record | `docs/reconstruction/functions/aa_007a69d0_FUN_007a69d0.md` |
| Live Ghidra | `decompile_function` `0x007a69d0`; `analyze_function_complete`; `get_function_by_address` body `007a69d0`–`007a6a29`; `read_memory` body 90 B; atexit thunk `0x009c30b0`; dtor `0x007a6890` |
| Consumer plate | `NDUIWindow_LoadInterfaceFile` dual: `localeCode = *(int*)(FUN_007a69d0() + 0x2c)` codes 0/1/2/3 → en/`_fr`/`_de`/`_uk` |

---

## 3. Signature

```c
// __cdecl — plain RET after SEH frame teardown; no stack args
void * /* LocaleStringTable* */ Locale_GetInstance_Inferred(void);
// Return: EAX = &DAT_00d1f660 (always)
```

| Item | Evidence |
|---|---|
| Convention | Epilogue `ADD ESP,0xC; RET` — frame-only; **not** `RET n` → **no callee-cleaned args** |
| Parameters | `parameters: []` (`analyze_function_complete`) |
| Callees | `FUN_007a6910`, `_atexit` only |
| Body range | Entry `007a69d0`, last insn `007a6a29` (`get_function_by_address`) |
| Xrefs | **538** inventory / ~100 listed + massive caller list (chat, inventory UI, mission dialogs, auth, skills) |

---

## 4. Control flow (sealed)

```
install MSVC SEH frame (fs:[0])
if (DAT_00d1f728 & 1) == 0:
    DAT_00d1f728 |= 1
    FUN_007a6910(&DAT_00d1f660)     // ctor
    _atexit(LAB_009c30b0)           // → dtor FUN_007a6890(this=&DAT_00d1f660)
restore ExceptionList
return &DAT_00d1f660
```

| Stage | Match raw ≡ decompile ≡ bytes |
|---|---|
| Once-flag bit0 test/set | **Yes** — `TEST [DAT_00d1f728], AL=1` / `OR [DAT], EAX=1` |
| First-call ctor only | **Yes** — `JNZ` skip when bit set |
| atexit registration once | **Yes** — only on cold path |
| Always return static object | **Yes** — `MOV EAX, 0x00d1f660` |

**Thread safety:** none (classic non-atomic once-flag). Assumed single-threaded init.

---

## 5. Machine bytes (`read_memory` @ `0x007a69d0`, 90 B)

```
64 A1 00 00 00 00        mov  eax, fs:[0]
6A FF                    push -1
68 DE B5 9A 00           push LAB_009ab5de
50                       push eax
B8 01 00 00 00           mov  eax, 1
84 05 28 F7 D1 00        test byte/dword [DAT_00d1f728], al   ; bit0
64 89 25 00 00 00 00     mov  fs:[0], esp
75 25                    jnz  already_init                   ; → 0x007a6a17
09 05 28 F7 D1 00        or   [DAT_00d1f728], eax            ; set bit0
68 60 F6 D1 00           push &DAT_00d1f660
C7 44 24 0C 00 00 00 00  mov  dword [esp+0xC], 0             ; SEH state
E8 06 FF FF FF           call FUN_007a6910                   ; → 0x007a6910
68 B0 30 9C 00           push LAB_009c30b0
E8 C2 2E CE FF           call _atexit
83 C4 04                 add  esp, 4
8B 0C 24                 mov  ecx, [esp]                     ; already_init
B8 60 F6 D1 00           mov  eax, 0x00d1f660
64 89 0D 00 00 00 00     mov  fs:[0], ecx
83 C4 0C                 add  esp, 0xC
C3                       ret
```

Hex (90 B):  
`64a1000000006aff68deb59a0050b801000000840528f7d100648925000000007525090528f7d1006860f6d100c744240c00000000e806ffffff68b0309c00e8c22eceff83c4048b0c24b860f6d10064890d0000000083c40cc3`

Decompile ≡ bytes. **No conflict.**

### atexit thunk (`read_memory` @ `0x009c30b0`)

```
B9 60 F6 D1 00   mov  ecx, 0x00d1f660
E9 .. .. .. ..   jmp  FUN_007a6890          ; target 0x007a6890
```

Dtor frees 10 ring slots (`this+4` …) and language-pack pointer tables — **not** owned deep here.

---

## 6. Globals / layout (this unit)

| Symbol | VA | Role | Confidence |
|---|---|---|---|
| `DAT_00d1f660` | `0x00d1f660` | Singleton object storage | **High** |
| `DAT_00d1f728` | `0x00d1f728` | Once-init flag dword; **bit0** used | **High** |
| Object span | `0xC8` B (`0x728−0x660`) | Fits ctor fields through `+0xc4` | **High** |
| `this+0x2c` | locale code int | Default **0** in ctor; consumer codes 1/2/3 = FR/DE/UK | **High** (read site + ctor store) |
| `PTR_FUN_00a96f88` | vtable stamp in ctor/dtor | Class identity | **High** (offset); product name open |

---

## 7. What this unit is **not**

| False identity | Why falsified |
|---|---|
| Chat / toast printer | No string args; no `FUN_007fdfb0` |
| `FUN_007a6de0` Localize | Separate thiscall; uses `this+0x2c` when locale arg = −1 |
| Config file parser | No file IO; LoadVogIni may **call** getter only |
| Returns int success | Returns **pointer** in EAX |

---

## 8. Related units (not dual-owned here)

| VA | Role |
|---|---|
| `0x007a6910` | Object ctor (buffers ×10 of 0x100, zeros, `+0x2c=0`) |
| `0x007a6890` | Object dtor (atexit target) |
| `0x007a6880` | `GetLocaleCode`: `return *(this+0x2c)` |
| `0x007a6de0` | Localize / copy English or pack-lookup into ring buffer |
| `0x007a66f0` | Load `languageFR/DE/UK%d.pak` into object |

---

## 9. Gaps / open

1. Product/PDB class name (leave `_Inferred` until string/RTTI).
2. Full field map of the 0xC8 object beyond `+0x2c` / ring / pack tables (ctor dual residual).
3. Whether any path clears `DAT_00d1f728` bit0 after init (none in this unit).
4. Runtime / bit-exact / differential — open.
5. Exhaustive 538-xref audit — not owned.

**Verdict:** **accept**
