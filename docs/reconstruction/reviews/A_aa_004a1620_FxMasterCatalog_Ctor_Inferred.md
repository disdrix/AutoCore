# Review A (reconstruction fidelity): `aa_004a1620` FxMasterCatalog_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a1620` |
| **VA** | `0x004a1620` |
| **Canonical name (Ghidra)** | `FUN_004a1620` |
| **Proposed name** | `FxMasterCatalog_Ctor_Inferred` (**High** role; product English absent) |
| **Prior scaffold alias** | `Named_CalleeOf_Named_VOG_DEBUG_STOP_004a1620` — chain-of-callers only |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_004a1620_FxMasterCatalog_Ctor_Inferred.md` |
| **System** | `client-fx` / FX master catalog host |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Construct an 8-byte FX master catalog host** used at `obj+0x88` by `Object_EnsureFxMasterFromDef` / preload / clonebase paths.

Host layout after ctor:

| Offset | Field |
|---|---|
| `+0x0` | `map*` — `std::map`-like header (`0xc` heap block) |
| `+0x4` | flag byte → 0 |
| `+0x5` | flag byte → 0 (later set by LoadMaster when any FX has `+0x58 != -1`) |
| `+0x6` | flag byte → 0 (set 1 by LoadMasterFromXML on entry) |

Map header (`operator_new(0xc)`):

| Offset | Field |
|---|---|
| `+0x0` | unused / pad in this ctor path (not written beyond node root) |
| `+0x4` | sentinel RB-node from `FUN_00439770` |
| `+0x8` | size = 0 |

Sentinel node: `+0x15 = 1` (red-black color/nil), parent/left/right all self-pointing — empty tree.

Also **lazy-once global FX master state**: if `DAT_00b03628 == 0`, set it 1 and zero `DAT_00b035e4..00b035f8` (6 dwords).

Returns `param_1` (host pointer) in EAX.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` + `analyze_function_complete` @ `0x004a1620` |
| Raw / annotated / clean | `aa_004a1620` three-rep |
| Function record | `docs/reconstruction/functions/aa_004a1620_FUN_004a1620.md` |
| Consumer dual | `A_aa_004eb3b0_Object_EnsureFxMasterFromDef_Inferred.md` — `new(8)+this` |
| Load sibling | `A_aa_004a6390_FxMaster_LoadMasterFromXML_Inferred.md` |
| Event dispatch | `A_aa_004a16d0_FxMaster_LoadEventVariant_Inferred.md` — map consumer |

**This pass:** live decompile; 7 xrefs; callee CF. **Not performed:** Launcher, runtime, ledgers.

---

## 3. Signature

```c
// __fastcall: ECX = 8-byte host (pre-allocated by callers via operator_new(8))
// Returns host in EAX
void * __fastcall FxMasterCatalog_Ctor_Inferred(void *host /* ECX */);
```

SEH (`LAB_009a102b`).

---

## 4. Callers / callees

| Callee | Role |
|---|---|
| `operator_new(0xc)` | Map header allocation |
| `FUN_00439770` | RB-tree sentinel / empty node factory |

Callers (7): `FUN_004eb3b0`, `FUN_004f1c70`, `FUN_004f1e20`, `FUN_00531330`, `FUN_00541aa0`, `FUN_00581940`, `FUN_005d9af0`.

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Zero host flags +4/+5/+6 | Yes |
| `new(0xc)` map header | Yes |
| Null alloc → store null map | Yes |
| Else sentinel via `00439770` + size 0 | Yes |
| Store map at `*host` | Yes |
| Lazy global init `DAT_00b03628` block | Yes |
| Return host | Yes |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| 8-byte catalog host ctor | **High** | consumers `new(8)` then this |
| Map is empty std::map-like int→FX* | **High** | LoadMaster insert + LoadEventVariant lower_bound |
| Flags at +4/+5/+6 | **High** | explicit stores; LoadMaster uses +5/+6 |
| `FUN_00439770` = empty RB node | **High** | self-links + `+0x15=1` |
| Lazy global table `00b035e4..f8` | **High** CF | English purpose **Tentative** |
| Product class name | **Tentative** | `_Inferred` |

---

## 7. Gaps / open

1. Exact product name of host / map value type.
2. Role of each global in `00b035e4..f8` (shared FX session counters?).
3. Whether `+4` flag is ever written after ctor (LoadMaster writes +5/+6 only in body seen).
4. Runtime not run.

**Verdict:** **accept-with-gaps** — ctor CF + layout High.
