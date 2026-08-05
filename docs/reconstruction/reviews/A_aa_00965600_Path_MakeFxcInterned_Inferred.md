# Review A (reconstruction fidelity): `aa_00965600` Path_MakeFxcInterned_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00965600` |
| **VA** | `0x00965600` |
| **Body** | `0x00965600`–`0x00965742` inclusive (**323 B** / `0x143`); pad `CC` then next @ `0x00965750` |
| **Canonical name** | `Path_MakeFxcInterned_Inferred` (**Inferred**); Ghidra `FUN_00965600` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00965600_Path_MakeFxcInterned_Inferred.md` |
| **System** | Client effects / path → interned string |
| **Live tools** | Ghidra `batch_decompile`, `analyze_function_complete`, `read_memory`, xrefs, `get_assembly_context` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — CF/ABI/`.fxc`/intern wiring sealed; product plate + handle type open |
| **Dual status** | **Present (W38-AF)** |

---

## 1. Purpose

Transform a path object into an **interned `.fxc`** (compiled effect) string handle:

```
c = pathObj->c_str_field;   // *pathObj as char*; null → ""
if (strlen(c) == 0):
  *out = DAT_00d1ed24;      // empty handle
  return out;

s = string(c);
pos = s.rfind('.');
if (pos == npos):
  s += ".fxc";
  FUN_00989e00(mgr@0x00d1eac8, out, s.c_str());
else:
  t = s.substr(0, pos);
  t += ".fxc";
  FUN_00989e00(mgr@0x00d1eac8, out, t.c_str());
return out;
```

**ABI:** `__cdecl`; stack `(outHandle*, pathObj*)`; returns `outHandle*`; caller `ADD ESP,8`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | Ghidra `batch_decompile` `0x00965600` (2026-08-04) — CF spine ≡ scaffold raw |
| Complete analysis | 2 xrefs; callers `FUN_009701d0`, `FUN_00751da0`; callees string ops + `FUN_00989e00` |
| Machine | `read_memory` `0x00965600` length 512 → body **323 B** then `CC` |
| Intern callee | `FUN_00989e00` decompile (not OWN) — thiscall intern on mgr |
| Parent consumer | W37-Q `EffEffectSlot_BindByPath_Inferred` dual |
| Call sites | `get_assembly_context` @ `00970236`, `00751e0a` — both `ADD ESP,8` |
| Scaffold | `raw/aa_00965600_*`, `reconstructed-exact/FUN_00965600.cpp` |

**Not performed:** Launcher, runtime golden, bit-exact image diff, parent ledger edits.

---

## 3. Machine seal (`read_memory`)

| Claim | Evidence | Conf |
|---|---|---|
| SEH prolog | `64 a1 … 6a ff 68 be f9 9a 00` | **Confirmed** |
| Empty → `DAT_00d1ed24` + early ret | `8b 0d 24 ed d1 00` … `89 4d 00` … `83 c4 44 c3` | **Confirmed** |
| `rfind` of `'.'` (`0x2e`) | `c6 44 24 60 2e` + `ff 15 … rfind` | **Confirmed** |
| npos branch vs strip | `3b 01` vs npos; `74 4e` → no-dot path | **Confirmed** |
| substr length = rfind result | fall-through: `50 6a 00 lea dest; call substr` | **Confirmed** |
| `".fxc"` @ `0x00aa42cc` | `68 cc 42 aa 00` both branches; `read_memory` → `.fxc\0` | **Confirmed** |
| Intern this = `0x00d1eac8` | `b9 c8 ea d1 00` + `e8 …` → `FUN_00989e00` | **Confirmed** |
| Body 323 B / end `0x00965742` | last `83 c4 44 c3`; next `CC` | **Confirmed** |
| cdecl 2-arg | callers `ADD ESP,8` | **Confirmed** |

Full hex (323 B):

```
64a1000000006aff68bef99a00508b442414648925000000008b1083ec3885d2558b6c244c578b3dbca2af008bc275028bc7568d70018a0883c00184c975f72bc6894424585e751c8b0d24edd1005f894d008bc55d8b4c243864890d0000000083c444c385d275028bd7528d4c240cff15f8629c00c7442448000000008b15d8629c008b026a01508d44245c508d4c2414c64424602eff15fc629c008b0dd8629c003b018d4c2408744e506a008d54242c52ff15e4629c0068cc42aa008d4c2428c644244c01ff15b0629c00837c243c108b44242873048d4424285055b9c8ead100e8194702008d4c2424c644244800ff15f4629c00eb2668cc42aa00ff15b0629c00837c2420108b44240c73048d44240c5055b9c8ead100e8e24602008d4c2408c7442448ffffffffff15f4629c008b4c24405f8bc55d64890d0000000083c444c3
```

---

## 4. Callers / callees

| Direction | Detail |
|---|---|
| Callees | `basic_string` ctor/dtor/rfind/substr/`+=`; `FUN_00989e00` (mgr `0x00d1eac8`) |
| Callers | `FUN_009701d0` (debug fxc notify path); `FUN_00751da0` |

---

## 5. Confidence table

| Claim | Level |
|---|---|
| Control flow ≡ live | **Confirmed** |
| cdecl + `ADD ESP,8` | **Confirmed** |
| `.fxc` extension policy | **Confirmed** |
| Intern via `00989e00` + mgr | **Confirmed** |
| Empty handle `DAT_00d1ed24` | **Confirmed** |
| Product class / plate English | **None** |
| Exact out-handle type demangle | **Tentative** |

---

## 6. Verdict

**accept-with-gaps** — structural path→`.fxc`→intern sealed; leave product naming and handle-type demangle open.
