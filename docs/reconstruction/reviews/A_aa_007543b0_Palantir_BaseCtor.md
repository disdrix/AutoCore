# Review A (reconstruction fidelity): `aa_007543b0` Palantir_BaseCtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_007543b0` |
| **VA** | `0x007543b0`–`0x0075447C` exclusive (**204 B**) |
| **Canonical name** | `Palantir_BaseCtor` |
| **Ghidra name** | `FUN_007543b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-I) |
| **Counterpart** | `reviews/B_aa_007543b0_Palantir_BaseCtor.md` |
| **System** | client / Palantir host base constructor |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full 204 B) + caller `FUN_007a26c0` + nested `FUN_0075d470` decompile + W34-K vtbl/dtor pair. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Base/placement constructor for the Palantir host object: publish `DAT_00d1f058`, install Palantir vtbl, initialize COM apartment, construct nested NDResourceCache at `+0x30`, publish path-list shell at `+0xA0`, construct `basic_string(".")` at `+0xB4`, set tail flags. Returns `self`. Does not allocate or free the outer object.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W35-I append) | `docs/reconstruction/raw/aa_007543b0_FUN_007543b0.md` |
| Annotated | `docs/reconstruction/raw/aa_007543b0_FUN_007543b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Palantir_BaseCtor.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_007543b0.cpp` |
| Function records | `functions/aa_007543b0_FUN_007543b0.md`, `functions/aa_007543b0_Palantir_BaseCtor.md` |
| Pair dtor | `aa_00754320` Palantir_CompleteDtor (W34-K) |
| Nested cache ctor | `FUN_0075d470` (unowned) |
| Live | decompile + 204 B hex + sole xref |

---

## 3. Signature (sealed)

```c
// stack self*; RET 4; EAX=self
Palantir* Palantir_BaseCtor(Palantir* self /*stack*/);
```

| Formal | Source | Conf |
|---|---|---|
| self | Stack `[esp+0x18]` → ESI after SEH+EBX/ESI | **High** |
| return | `MOV EAX,ESI` | **High** |
| cleanup | `ADD ESP,0xC; RET 4` | **High** |
| ECX-thiscall | **No** | **High** |

Decompiler `undefined FUN_007543b0(void)` is incomplete — do not trust as full ABI.

---

## 4. Control flow (bytes authority)

```
DAT_00d1f058 = self
*self = PTR_FUN_00a9f76c
[+4]=0 [+5]=1 [+6]=0
[+8]=DAT_00d1f01c [+0xC]=DAT_00d1f020
[+0x14..+0x20]=0
CoInitializeEx(0, 2)
[+0x24]=-1 [+0x28]=0 [+0x2C]=0
FUN_0075d470(self+0x30)
DAT_00d1f1fc = self+0xA0; triad zero
basic_string(self+0xB4, ".")
[+0xD0]=1 [+0xD1]=0 [+0xD4]=0
return self
```

| Stage | Match | Conf |
|---|---|---|
| Singleton publish | `A3 58 F0 D1 00` | **High** |
| Vtbl install | `C7 06 6C F7 A9 00` | **High** |
| Nested cache @ `+0x30` | `LEA EAX,[ESI+0x30]; PUSH; CALL FUN_0075d470` | **High** |
| Path shell @ `+0xA0` | `LEA EAX,[ESI+0xA0]; MOV DAT_00d1f1fc,EAX` | **High** |
| String @ `+0xB4` | `LEA ECX,[ESI+0xB4]` + IAT ctor + `"."` @ `0x00a2e610` | **High** |
| Product class Palantir | vtbl peer W34-K | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (204 B) — see raw W35-I append.

Entry: `64 A1 … 6A FF 68 58 FD 9A 00 … 8B 74 24 18`  
Epilogue: `8B C6 5E 64 89 0D… 5B 83 C4 0C C2 04 00`  
Pad: `CC`; next `FUN_00754480` (Palantir ResetDevice).

**Decompile ≢ bytes** on ABI display; CF order matches. **Bytes win** for ABI.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_007a26c0` only (1 xref) — derived host overwrites vtbl after |
| Callees | `CoInitializeEx`, `FUN_0075d470`, `basic_string` ctor |
| Vtbl | `PTR_FUN_00a9f76c` |

---

## 7. Gaps

1. Nested dual for `FUN_0075d470` (full NDResourceCache ctor plate).  
2. Subobject at `+0x10` (dtor-only in W34-K; not constructed here).  
3. Exact MSVC demangle plate / full Palantir POD size.  
4. Runtime / bit-exact / differential.

---

## 8. Verdict

ABI, globals, member offsets, and product class sealed by full-body hex + W34-K vtbl/dtor pair; nested cache ctor dual open → **accept-with-gaps**.
