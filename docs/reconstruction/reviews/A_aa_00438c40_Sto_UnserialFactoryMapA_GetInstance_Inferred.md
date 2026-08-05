# Review A (reconstruction fidelity): `aa_00438c40` Sto_UnserialFactoryMapA_GetInstance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00438c40` |
| **VA** | `0x00438c40`–`0x00438c99` (**90 B**) |
| **Canonical name** | `Sto_UnserialFactoryMapA_GetInstance_Inferred` (was `FUN_00438c40`) |
| **Review date** | `2026-07-29` (W35-D) |
| **Reviewer role** | Reconstruction fidelity (Meyers NestedHash factory-map getter) |
| **Counterpart** | `reviews/B_aa_00438c40_Sto_UnserialFactoryMapA_GetInstance_Inferred.md` |
| **System** | arda2/storage — stoAbstractUnserializationFactory map A |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + `get_function_xrefs`. Prefer decompile/read_memory (**no** `disassemble_bytes`). Context-only: NestedHash ctor W34-E `0x00457ac0`, atexit thunk `0x009c3310`, callers `FUN_004449b0` / `FUN_00437b00` (not owned).

---

## 1. Purpose

**Meyers-style singleton getter** for the process-wide NestedHash bag at **`DAT_00d1fd18`**, used as **creator-tag map A** for `stoAbstractUnserializationFactory`.

On first entry (once-flag `DAT_00d1fd40` bit0 clear):

1. Set once-flag bit0.
2. Construct bag via **`FUN_00457ac0(&DAT_00d1fd18)`** = `NestedHash_Ctor_Sentinel0x10_Inferred` (node **0x10**, span **0x28**, 9 buckets — W34-E).
3. Register **`_atexit(LAB_009c3310)`** — thunk: `MOV EAX,&DAT_00d1fd18; JMP 0x004493eb` → **`RET 4`** (no NestedHash deep free).

Always returns **`&DAT_00d1fd18`** in **EAX**.

This unit does **not** insert tags, log duplicates, or invoke creators — those live in callers.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00438c40_FUN_00438c40.md` (+ W35-D append) |
| Annotated | `docs/reconstruction/raw/aa_00438c40_FUN_00438c40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Sto_UnserialFactoryMapA_GetInstance_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00438c40.cpp` |
| Function record | `docs/reconstruction/functions/aa_00438c40_FUN_00438c40.md` |
| Named record | `docs/reconstruction/functions/aa_00438c40_Sto_UnserialFactoryMapA_GetInstance_Inferred.md` |
| Live Ghidra | decompile ≡ raw; body `00438c40`–`00438c99`; full 90 B hex; atexit 10 B |
| Callers | `FUN_004449b0` (string `stoAbstractUnserializationFactory.h`); `FUN_00437b00` |
| Ctor family | W34-E `NestedHash_Ctor_Sentinel0x10_Inferred` |

---

## 3. Signature

```c
// __cdecl — plain RET after SEH frame teardown; no stack args
NestedHash_Sentinel0x10* Sto_UnserialFactoryMapA_GetInstance_Inferred(void);
// Return: EAX = &DAT_00d1fd18 (always)
```

| Item | Evidence |
|---|---|
| Convention | Epilogue `ADD ESP,0xC; RET` — frame-only; **not** `RET n` |
| Parameters | `parameters: []` (`analyze_function_complete`) |
| Callees | `FUN_00457ac0`, `_atexit` only |
| Body range | Entry `00438c40`, last insn `00438c99` (`get_function_by_address`) |
| Xrefs | **5** call sites / **2** caller functions |

---

## 4. Control flow (sealed)

```
install MSVC SEH frame (fs:[0], LAB_009bcc4d)
if (DAT_00d1fd40 & 1) == 0:
    DAT_00d1fd40 |= 1
    FUN_00457ac0(&DAT_00d1fd18)     // NestedHash 0x10 ctor
    _atexit(LAB_009c3310)           // → RET4 no-op
restore ExceptionList
return &DAT_00d1fd18
```

| Stage | Match raw ≡ decompile ≡ bytes |
|---|---|
| Once-flag bit0 test/set | **Yes** — `TEST [DAT_00d1fd40], AL=1` / `OR [DAT], EAX=1` |
| First-call ctor only | **Yes** — `JNZ` skip when bit set |
| atexit registration once | **Yes** — only on cold path |
| Always return static object | **Yes** — `MOV EAX, 0x00d1fd18` |
| Call target `FUN_00457ac0` | **Yes** — rel `+0x1ee46` from `0x00438c7a` |

**Thread safety:** none (classic non-atomic once-flag). Assumed single-threaded init.

---

## 5. Machine bytes (`read_memory` @ `0x00438c40`, 90 B)

```
64 A1 00 00 00 00        mov  eax, fs:[0]
6A FF                    push -1
68 4D CC 9B 00           push LAB_009bcc4d
50                       push eax
B8 01 00 00 00           mov  eax, 1
84 05 40 FD D1 00        test [DAT_00d1fd40], al   ; bit0
64 89 25 00 00 00 00     mov  fs:[0], esp
75 25                    jnz  already_init
09 05 40 FD D1 00        or   [DAT_00d1fd40], eax  ; set bit0
68 18 FD D1 00           push &DAT_00d1fd18
C7 44 24 0C 00 00 00 00  mov  dword [esp+0xC], 0
E8 46 EE 01 00           call FUN_00457ac0
68 10 33 9C 00           push LAB_009c3310
E8 52 0C 05 00           call _atexit
83 C4 04                 add  esp, 4
8B 0C 24                 mov  ecx, [esp]           ; already_init
B8 18 FD D1 00           mov  eax, 0x00d1fd18
64 89 0D 00 00 00 00     mov  fs:[0], ecx
83 C4 0C                 add  esp, 0xC
C3                       ret
```

Hex (90 B):  
`64a1000000006aff684dcc9b0050b801000000840540fdd100648925000000007525090540fdd1006818fdd100c744240c00000000e846ee01006810339c00e8520c050083c4048b0c24b818fdd10064890d0000000083c40cc3`

Decompile ≡ bytes. **No conflict.**

### atexit thunk (`read_memory` @ `0x009c3310`)

```
B8 18 FD D1 00           mov  eax, 0x00d1fd18
E9 D6 60 A8 FF           jmp  0x004493eb          ; RET 4 inside FUN_004493d0
```

---

## 6. Classification / naming

| Item | Value |
|---|---|
| Classification | **worker** (getter; side-effect once-init) |
| Name | `Sto_UnserialFactoryMapA_GetInstance_Inferred` |
| Reject | scaffold `Named_CalleeOf_*_gfxBody_*` |
| Twin | MapB `0x00438ca0` |
| Family | NestedHash static getters (with W35-E `FUN_0044fee0` third bag) |

---

## 7. Gaps

- Product/PDB English for creator-node type / tag domain "A".
- Map ops `FUN_0046c1b0` / `FUN_0046bf90` unowned.
- Why atexit is no-op (heap teardown at process exit is sufficient; not proven product intent).
- Runtime / bit-exact / differential.

---

## 8. Verdict

**accept-with-gaps** — ABI, once-flag, static NestedHash address, ctor callee, exclusive Sto factory callers, and decompile≡bytes are sealed. Product English for map contents remains open (`_Inferred`).
