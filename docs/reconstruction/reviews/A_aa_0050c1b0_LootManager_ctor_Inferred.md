# Review A (reconstruction fidelity): `aa_0050c1b0` LootManager_ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0050c1b0` |
| **VA** | `0x0050c1b0` |
| **Canonical name** | `LootManager_ctor_Inferred` (leave-FUN retail) |
| **Prior names** | `FUN_0050c1b0`; scaffold Named_CalleeOf_OnDeath (mis-role); raw **"Error: Decompilation failed"** |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (fidelity / clean ≡ raw) |
| **Counterpart** | `reviews/B_aa_0050c1b0_LootManager_ctor_Inferred.md` |
| **System** | missions-progression / combat death loot (manager lifecycle) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Constructor** for the global **loot / economy content manager** object stored in `DAT_00b037e8`.

Parent death path:

```c
pv = operator_new(0xbc);
DAT_00b037e8 = FUN_0050c1b0(DAT_00b041fc);  // thiscall: ECX=new, arg0=global ctx
```

Live decompile (2026-07-29) shows a large `__thiscall` ctor:

* Install primary vtable `PTR_FUN_009cdd3c` and secondary `PTR_FUN_009cdd30` at `this+0xc`
* Init multiple red-black / tree sentinels via `FUN_00439770` (`this+0x1e`, `this+0x2d` slots)
* Vector ctors at `this+0x20` (4 × 0xc) via `_eh_vector_constructor_iterator_`
* Allocate pairs via `operator_new(0x14)` + `FUN_006049b0` → `this[1]`, `this[2]`
* Allocate **six** `0x3c` blocks via `FUN_00603160` → `this[0x17..0x1c]`
* `DAT_00b041d4 = param_2` (stash global context pointer used later by `00509010` hash at `+0xf14`)
* Load content tables (COM/CoTaskMem paths, wide→multi-byte names, per-record `FUN_00600760` / `FUN_00600970` factories) into pointer arrays at `this[0x11]`, `this[0x12]`, `this[0x16]`, …
* Dual path when `DAT_00b04694 != 0`: use prebaked `DAT_00b046b8/c8/…` buffers instead of live loaders
* Counts published to globals `DAT_00d02974`, `DAT_00d02978`, `DAT_00d02984`, …

Also referenced from `FUN_004cd670`, `FUN_004ce940` (non-death init paths).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / clean scaffold | **Failed decompile** placeholder only |
| Live decompile | Ghidra `0x0050c1b0` full (large; MCP truncated mid-body) |
| Parent use | `aa_004da630` lazy-init `DAT_00b037e8` |
| Size | `operator_new(0xbc)` → object **0xBC** bytes |

---

## 3. Control flow (sealed structure)

```
LootManager_ctor(this, globalCtx):
  SEH frame
  *this = vtbl_009cdd3c
  FUN_005113e0()
  this[3] = vtbl_009cdd30
  this[0x10] = 0
  // tree A @ this[0x1e], count this[0x1f]
  // 4× vector elements this+0x20
  // tree B @ this[0x2d], count this[0x2e]
  // clear this[0x11..0x14]
  this[1] = new FUN_006049b0 or 0
  this[2] = new FUN_006049b0 or 0
  DAT_00b041d4 = globalCtx
  this[0x17..0x1c] = six × new FUN_00603160 or 0
  FUN_007c7200 / FUN_00604ab0 / free temp COM buffers …
  // For each content family (flag DAT_00b04694 offline vs online):
  //   load N records stride 0x178 / 0x11c / …
  //   convert LPCWSTR names; construct typed records; store in this[0x11/0x12/0x16/…]
  //   optional validation FUN_005e0580 / FUN_0050fcd0 / FUN_004073a0
  return this
```

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Is a ctor (new 0xbc + thiscall) | **High** | parent pattern |
| Installs vtables 009cdd3c / 009cdd30 | **High** | |
| Sets `DAT_00b041d4 = arg` | **High** | links to 00509010 hash root |
| Multiple table pointer arrays on object | **High** | |
| Offline path via DAT_00b04694 + baked buffers | **High** | |
| Record strides 0x178 / 0x11c observed | **High** | in first two loaders |
| Complete enumeration of every sub-table | **Probable** | decomp truncated / huge |
| Exact retail class name | **Open** | inferred LootManager |
| Scaffold “OnDeathAwardKillXp callee helper” role | **Rejected** | ctor, not per-kill logic |

---

## 5. Control flow: clean ≡ raw

**No** — raw/clean are **failure stubs**. Live Ghidra is authoritative until re-captured raw.

---

## 6. Gaps / open

1. Re-capture raw/annotated/clean from live decompile (out of OWN dual scope unless requested).
2. Name each `this[0x11/12/16/…]` table family.
3. Full offline vs online loader parity for remaining families after MCP truncate.
4. Dtor / lifetime of `DAT_00b037e8`.

**Verdict:** Role + structure **High**. Full field catalog **accept-with-gaps**. Scaffold failure noted.
