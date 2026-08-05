# Review A (reconstruction fidelity): `aa_005b2830` VehicleNet_PackOwnerSkillsHB

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b2830` |
| **VA** | `0x005b2830` |
| **Canonical name** | `VehicleNet_PackOwnerSkillsHB` (inferred; Ghidra `FUN_005b2830`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005b2830_VehicleNet_PackOwnerSkillsHB.md` |
| **System** | input-drive-control / GhostVehicle skills mask |
| **Evidence pass** | Live `batch_decompile` + callees; parent dual `aa_005f5de0`; related `CVOGHBBase_GetRemainingSeconds` dual |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Delta SkillsMask (`0x80`)** path helper: walk owner’s **CVOGHBBase** hotbar/skill list, collect active entries that still have remaining time (or sentinel period), pack:

1. **8-bit count** of selected entries (0 → early empty path).
2. If count ≠ 0: **16-bit** first-entry field + `FUN_005b13f0` bulk pack of first node payload, then free temps.

Selection gate per HB node:

```
nUnusedOrFlags == 1
AND ( nPeriodSentinel == -1000  OR  GetRemainingSeconds(node) > DAT_00a0f298 )
```

`DAT_00a0f298` = **0.5f** (`read_memory` → `00 00 00 3f`).

After walk: if lock byte at list-host `+0x28` set → clear + `LeaveCriticalSection(host+4)`.

**Not** the initial identity block (`0x005b1290`). Parent PackUpdate calls this only on **delta** skills path.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005b2830_FUN_005b2830.md` |
| Annotated | `docs/reconstruction/raw/aa_005b2830_FUN_005b2830.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_005b2830.cpp` |
| Function record | `docs/reconstruction/functions/aa_005b2830_FUN_005b2830.md` |
| Parent dual | `reviews/A_aa_005f5de0_VehicleNet_PackUpdate.md` |
| Related dual | `reviews/A_aa_00508280_CVOGHBBase_GetRemainingSeconds.md` |
| Constant | `DAT_00a0f298` = 0.5f |

**Three-rep:** present.

---

## 3. Signature (decompiler-shaped)

```c
// param_1 = BitStream* (or pack connection)
// param_2 = CVOGHBBase* list head / skill container root
void VehicleNet_PackOwnerSkillsHB(void *stream, CVOGHBBase *hbRoot);
```

Exact thiscall vs free-func **not fully sealed** (decomp free-func; SEH frame present). Callers from PackUpdate skills branch pass stream + owner skills root.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| Init temp vector (`local_18`…) + SEH | **Yes** | **High CF** |
| Iterate via `FUN_004022a0` until null | **Yes** | **High** |
| Gate: flags==1 AND (sentinel -1000 OR remaining &gt; 0.5f) | **Yes** | **High** |
| On hit: vtbl+0x28 / +0x20 extract; reject if payload `+0x21 == -1` | **Yes** | **High CF** |
| Push node record via `FUN_005b3110` | **Yes** | **High** |
| Unlock critical section if held | **Yes** | **High** |
| Count = `(end-begin)/0xc` as **byte** | **Yes** | **High** |
| `writeBits(8, count)` | **Yes** | **High** |
| If count: write 16b first + `FUN_005b13f0` + delete | **Yes** | **High CF** |
| Else free empty vector if any | **Yes** | **High** |

### Decompiler hazards

- `operator_delete` marked “does not return” — **false**; normal free.
- `this[0x27].…` field aliases for a dword at large offset — treat as raw dword copy into pack record, not English layout.
- Count formula assumes **12-byte** (`0xc`) records.

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| SkillsMask delta packer (not identity) | **High** | parent dual + CF |
| 0.5f remaining-time threshold | **High** | constant bytes |
| Sentinel −1000 bypasses timer | **High** | live cmp |
| 8-bit count on wire | **High** | writeBits 8 |
| First-entry special + bulk helper `0x005b13f0` | **High CF** | live |
| Product English for HB node fields | **Low–Medium** | residual |
| Full multi-entry wire shape inside `FUN_005b13f0` | **Open** | out of own VA |
| Bit-exact / runtime | **Open** | deferred |

---

## 6. Gaps

1. Own dual for `FUN_005b13f0` / `FUN_005b3110` (pack record format).
2. Exact C++ type of `param_2` beyond CVOGHBBase labeling.
3. Whether count caps at 255 silently (byte cast).
4. Why only first entry’s 16b is written before bulk helper (helper may emit rest).

**Verdict:** **accept-with-gaps**
