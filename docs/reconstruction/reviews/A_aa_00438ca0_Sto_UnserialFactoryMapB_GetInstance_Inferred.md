# Review A (reconstruction fidelity): `aa_00438ca0` Sto_UnserialFactoryMapB_GetInstance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00438ca0` |
| **VA** | `0x00438ca0`–`0x00438cf9` (**90 B**) |
| **Canonical name** | `Sto_UnserialFactoryMapB_GetInstance_Inferred` (was `FUN_00438ca0`) |
| **Review date** | `2026-07-29` (W35-D) |
| **Reviewer role** | Reconstruction fidelity (Meyers NestedHash factory-map getter twin) |
| **Counterpart** | `reviews/B_aa_00438ca0_Sto_UnserialFactoryMapB_GetInstance_Inferred.md` |
| **System** | arda2/storage — stoAbstractUnserializationFactory map B |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + `get_function_xrefs`. Prefer decompile/read_memory (**no** `disassemble_bytes`). Context-only: NestedHash ctor W34-E, atexit `0x009c3300`, callers `FUN_00444a40` / `FUN_00437c90` (not owned).

---

## 1. Purpose

**Meyers-style singleton getter** for the process-wide NestedHash bag at **`DAT_00d1fcec`**, used as **creator-tag map B** for `stoAbstractUnserializationFactory` (sibling of MapA).

On first entry (once-flag `DAT_00d1fd14` bit0 clear):

1. Set once-flag bit0.
2. Construct bag via **`FUN_00457ac0(&DAT_00d1fcec)`** = same NestedHash **0x10** ctor as MapA.
3. Register **`_atexit(LAB_009c3300)`** — `MOV EAX,&DAT_00d1fcec; JMP 0x004493eb` → **`RET 4`** no-op free.

Always returns **`&DAT_00d1fcec`** in **EAX**.

**Twin of** `0x00438c40`: body template identical; only SEH/flag/static/atexit immediates and call relocs differ.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00438ca0_FUN_00438ca0.md` (+ W35-D append) |
| Annotated | `docs/reconstruction/raw/aa_00438ca0_FUN_00438ca0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Sto_UnserialFactoryMapB_GetInstance_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00438ca0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00438ca0_FUN_00438ca0.md` |
| Named record | `docs/reconstruction/functions/aa_00438ca0_Sto_UnserialFactoryMapB_GetInstance_Inferred.md` |
| Live Ghidra | decompile ≡ raw; body `00438ca0`–`00438cf9`; full 90 B hex |
| Callers | `FUN_00444a40` (same header string as MapA insert); `FUN_00437c90` |
| BSS | bag B between bag C (`d1fcc0`) and bag A (`d1fd18`) |

---

## 3. Signature

```c
// __cdecl — plain RET after SEH frame teardown; no stack args
NestedHash_Sentinel0x10* Sto_UnserialFactoryMapB_GetInstance_Inferred(void);
// Return: EAX = &DAT_00d1fcec (always)
```

| Item | Evidence |
|---|---|
| Convention | Epilogue `ADD ESP,0xC; RET` |
| Parameters | `parameters: []` |
| Callees | `FUN_00457ac0`, `_atexit` only |
| Body range | Entry `00438ca0`, last insn `00438cf9` |
| Xrefs | **5** call sites / **2** caller functions |

---

## 4. Control flow (sealed)

```
install MSVC SEH frame (fs:[0], LAB_009bcc2d)
if (DAT_00d1fd14 & 1) == 0:
    DAT_00d1fd14 |= 1
    FUN_00457ac0(&DAT_00d1fcec)
    _atexit(LAB_009c3300)
restore ExceptionList
return &DAT_00d1fcec
```

| Stage | Match raw ≡ decompile ≡ bytes |
|---|---|
| Once-flag bit0 test/set | **Yes** — `TEST [DAT_00d1fd14], AL=1` / `OR` |
| First-call ctor only | **Yes** |
| atexit once | **Yes** |
| Always return static | **Yes** — `MOV EAX, 0x00d1fcec` |
| Call target `FUN_00457ac0` | **Yes** — rel `+0x1ede6` from `0x00438cda` |

**Thread safety:** none.

---

## 5. Machine bytes (`read_memory` @ `0x00438ca0`, 90 B)

```
64 A1 00 00 00 00        mov  eax, fs:[0]
6A FF                    push -1
68 2D CC 9B 00           push LAB_009bcc2d
50                       push eax
B8 01 00 00 00           mov  eax, 1
84 05 14 FD D1 00        test [DAT_00d1fd14], al
64 89 25 00 00 00 00     mov  fs:[0], esp
75 25                    jnz  already_init
09 05 14 FD D1 00        or   [DAT_00d1fd14], eax
68 EC FC D1 00           push &DAT_00d1fcec
C7 44 24 0C 00 00 00 00  mov  dword [esp+0xC], 0
E8 E6 ED 01 00           call FUN_00457ac0
68 00 33 9C 00           push LAB_009c3300
E8 F2 0B 05 00           call _atexit
83 C4 04                 add  esp, 4
8B 0C 24                 mov  ecx, [esp]
B8 EC FC D1 00           mov  eax, 0x00d1fcec
64 89 0D 00 00 00 00     mov  fs:[0], ecx
83 C4 0C                 add  esp, 0xC
C3                       ret
```

Hex (90 B):  
`64a1000000006aff682dcc9b0050b801000000840514fdd100648925000000007525090514fdd10068ecfcd100c744240c00000000e8e6ed01006800339c00e8f20b050083c4048b0c24b8ecfcd10064890d0000000083c40cc3`

Decompile ≡ bytes. **No conflict.**

### atexit thunk (`read_memory` @ `0x009c3300`)

```
B8 EC FC D1 00           mov  eax, 0x00d1fcec
E9 E6 60 A8 FF           jmp  0x004493eb          ; same RET 4 as MapA
```

### Twin diff vs MapA (`0x00438c40`)

| Field | MapA | MapB |
|---|---|---|
| SEH | `LAB_009bcc4d` | `LAB_009bcc2d` |
| Once | `DAT_00d1fd40` | `DAT_00d1fd14` |
| Bag | `DAT_00d1fd18` | `DAT_00d1fcec` |
| atexit | `LAB_009c3310` | `LAB_009c3300` |
| Body size / CF | 90 B Meyers | **identical** |

---

## 6. Classification / naming

| Item | Value |
|---|---|
| Classification | **worker** |
| Name | `Sto_UnserialFactoryMapB_GetInstance_Inferred` |
| Reject | scaffold `Named_CalleeOf_*_gfxBody_*` |
| Twin | MapA `0x00438c40` |

---

## 7. Gaps

- Product distinction of map B vs A tag domains.
- Unowned map-op callees on insert/lookup paths.
- Runtime / bit-exact / differential.

---

## 8. Verdict

**accept-with-gaps** — twin fidelity sealed with MapA; exclusive Sto factory sibling callers sealed; product English open.
