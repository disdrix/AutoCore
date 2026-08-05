# Review A (reconstruction fidelity): `aa_00754ee0` GlyphCache_PlacementCtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00754ee0` |
| **VA** | `0x00754ee0`–`0x00754FAB` exclusive (**203 B**) |
| **Canonical name** | `GlyphCache_PlacementCtor` |
| **Ghidra name** | `FUN_00754ee0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-H) |
| **Counterpart** | `reviews/B_aa_00754ee0_GlyphCache_PlacementCtor.md` |
| **System** | GlyphCache placement ctor |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (203 B body + vtbl `00a9f584`). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Placement-construct a **GlyphCache** object (`0xB8` host): vtbl, refcount0, string, default globals, NestedHashBag at `+0x44`, zero remaining known slots. Sole caller `FUN_0073bc50` does `new(0xB8)` then this.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W35-H append) | `docs/reconstruction/raw/aa_00754ee0_FUN_00754ee0.md` |
| Annotated | `docs/reconstruction/raw/aa_00754ee0_FUN_00754ee0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GlyphCache_PlacementCtor.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00754ee0.cpp` |
| Function records | `functions/aa_00754ee0_FUN_00754ee0.md`, `functions/aa_00754ee0_GlyphCache_PlacementCtor.md` |
| Nested | W34-G `NestedHashBag_Ctor_Sentinel0x30_Inferred` @ `0x004438c0` |
| Live | decompile + 203 B hex + vtbl string |

---

## 3. Signature (sealed)

```c
// stack(self*); RET 4; returns self in EAX
GlyphCache* GlyphCache_PlacementCtor(GlyphCache* self /*stack*/);
```

| Formal | Source | Conf |
|---|---|---|
| self | Stack → ESI (`MOV ESI,[ESP+0x14]`) | **High** |
| return | `MOV EAX,ESI` | **High** |
| cleanup | `ADD ESP,0xC; RET 4` | **High** |
| ECX-thiscall | **No** | **High** |

---

## 4. Control flow (bytes authority)

```
SEH LAB_009b0971
self[+4]=0; self[+0]=PTR_FUN_00a9f584
self[+0xc..+0x14]=0
basic_string_ctor(self+0x18)
self[+0x38/+0x3c]=DAT_00d1f01c/020; self[+0x40]=0
FUN_004438c0(self+0x44)
zero +0x70..+0x80; zero +0x94..+0xac
self[+0xb0/+0xb4]=DAT_00d1f01c/020
return self; RET 4
```

| Stage | Match | Conf |
|---|---|---|
| SEH + ESI this | bytes | **High** |
| vtbl + string product | vtbl mem | **High** |
| NestedHashBag call | `E8`→`004438c0` | **High** |
| RET 4 | `C2 04 00` | **High** |
| Unwritten gaps | no stores | **High** |

---

## 5. Machine bytes (`read_memory`)

Full 203 B hex — raw W35-H append.  
Entry: `64 A1 00 00 00 00 6A FF 68 71 09 9B 00 …`  
Epilogue: `5E 83 C4 0C C2 04 00`  
Pad: `CC` then next @ `0x00754FB0`.

**Decompile ≡ CF stores;** analyze void prototype incomplete; **bytes win on ABI.**

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_0073bc50` @ `0x0073bd02` only |
| Callees | `basic_string` IAT; `FUN_004438c0` |

---

## 7. Gaps

1. Product meaning of `DAT_00d1f01c` / `DAT_00d1f020`.  
2. Unwritten `+0x08`, `+0x84..+0x93`.  
3. Complete dtor / vtbl[2] residual.  
4. Runtime / bit-exact / differential.

---

## 8. Verdict

**accept-with-gaps** — placement ABI, GlyphCache product identity, layout writes, and NestedHashBag nest sealed High; residual globals/dtor/unwritten slots only.
