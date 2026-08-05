# Review A (reconstruction fidelity): `aa_00542790` `FxCache_ApplyWithNfxEnsure`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00542790` |
| **VA** | `0x00542790` |
| **Body span** | `00542790`–`00542a8c` (**764 B**) |
| **Canonical name** | `FxCache_ApplyWithNfxEnsure` (structural **INFERRED**) |
| **Ghidra name** | `FUN_00542790` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W20-I) |
| **Counterpart** | `reviews/B_aa_00542790_FxCache_ApplyWithNfxEnsure.md` |
| **System** | `client-fx` / skills-abilities |
| **Live tools** | Ghidra `decompile_function` + `read_memory` + xrefs (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Full skill/FX apply with nfx master ensure** when the resource subsystem is live:

1. Gate `*(DAT_00d1f050+0x6c)`.
2. Snapshot transforms (`+0x160` or `DAT_009d00a8`).
3. Hash lookup key on `*(this+0xf0c)`.
4. If master flag clear: SkillDef → path + **`_nfx.xml`** → open → strip → `FxMaster_LoadMasterFromXML`.
5. Open/resolve FX → **entity `vtbl[+0x238]`** attach, else transform fallback.
6. Return **1** / **0** with SEH teardown.

Lighter sibling: `FxCache_EnsureMasterAndResolve` (`0x005408f0`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00542790_FUN_00542790.md` (+ 2026-07-29 live append) |
| Annotated | `docs/reconstruction/raw/aa_00542790_FUN_00542790.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FxCache_ApplyWithNfxEnsure.cpp` |
| Scaffold clean | `reconstructed-exact/FUN_00542790.cpp` |
| Function record | `docs/reconstruction/functions/aa_00542790_FxCache_ApplyWithNfxEnsure.md` |
| Live decompile | Ghidra @ `0x00542790` |
| Bytes | entry 128 B; exit @ `0x00542a70`; strings `0x009ca184`, `0x009d00a8` |
| Xrefs | `FUN_00512d10`, `FUN_005c74e0` (`CLoadNode::_initSpecialFX`) |
| Related | SkillDefMap duals; `FxMaster_LoadMasterFromXML`; sibling `aa_005408f0` |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Assembly-sealed claims (`read_memory`)

### Prologue + gate + early ret 0

```text
00542790  6A FF / 68 DF409A00 / fs:[0] SEH
005427a5  81 EC 60 04 00 00     sub  esp, 0x460
005427ab  A1 50 F0 D1 00        mov  eax, DAT_00d1f050
005427b0  8B 40 6C              mov  eax, [eax+0x6c]
005427b8  8B D1                 mov  edx, ecx           ; save this
005427be  75 1A                 jne  continue
005427c0  32 C0                 xor  al, al
...
005427d6  C2 1C 00              ret  0x1c
```

### Success epilogue

```text
... B0 01 ...                 mov  al, 1
... add esp, 0x46c ...
C2 1C 00                      ret  0x1c
CC CC CC
```

### Constants

| Addr | Content | Role |
|---|---|---|
| `0x009ca184` | `"_nfx.xml"` | path suffix (append + strstr strip) |
| `0x009d00a8` | `ffffffff ffffffff 00000000 00000000` | default 4-dword xform |

| Claim | Evidence | Conf |
|---|---|---|
| Body **764 B** | function bounds | **Confirmed** |
| **`ret 0x1c`** (7 stack args) | early + late `C2 1C 00` | **Confirmed** |
| SEH frame | prologue / LAB_009a40df | **Confirmed** |
| Gate `DAT_00d1f050+0x6c` | entry bytes | **Confirmed** |
| `_nfx.xml` string | `read_memory` | **Confirmed** |
| Live ≡ raw CF | side-by-side | **Confirmed** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = apply with nfx ensure | **High** | LoadMaster + vtbl + initSpecialFX caller |
| Transform snapshots `+0x160` | **Confirmed** | decompile + default DAT |
| Master gate `value+0x0a` | **Confirmed** | same family as 005408f0 |
| vtbl `+0x238` apply | **Confirmed** | decompile |
| Product method English | **Open** | |
| Resource helpers duals | **Open** | not OWN |
| Runtime | **Open** | |

---

## 5. Call graph (this unit)

**Callees:** `CNDHash_LookupByKey`, `SkillDefMap_GetGlobal`, `SkillDefMap_ExactFindByIntKey`, `FUN_00540090`, `FUN_00989e00`, `FUN_0043d670`, `FUN_004ed310`, `strstr`, `FxMaster_LoadMasterFromXML`, `FUN_00971820`, `FUN_0043d650`, `FUN_004a04f0`, `FUN_004a16d0`, `FUN_00545d70`, `FUN_005b2ba0`.

**Callers:**

| Symbol | VA | Note |
|---|---|---|
| `FUN_00512d10` | `0x00512d10` | when subsystem live + no out FX ptr |
| `FUN_005c74e0` | `0x005c74e0` | plate `CLoadNode::_initSpecialFX` |

---

## 6. Gaps

1. Product English for host / vtbl `+0x238` / transform fields.
2. Whether `_nfx.xml` double-append interacts badly with LoadMaster’s own append (body strips before call).
3. Duals of path/resource helpers.
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — ABI, gate, nfx path, apply CF sealed; naming + runtime residual.
