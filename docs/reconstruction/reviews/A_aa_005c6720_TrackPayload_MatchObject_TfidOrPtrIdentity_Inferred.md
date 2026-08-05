# Review A (reconstruction fidelity): `aa_005c6720` TrackPayload_MatchObject_TfidOrPtrIdentity_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c6720` |
| **VA** | `0x005c6720`–`0x005c6788` exclusive (**104 B** / `0x68`) |
| **Canonical name** | `TrackPayload_MatchObject_TfidOrPtrIdentity_Inferred` (**Inferred**); Ghidra `FUN_005c6720` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_005c6720_TrackPayload_MatchObject_TfidOrPtrIdentity_Inferred.md` |
| **System** | track-manager payload ↔ object match |
| **Live tools** | Ghidra `batch_decompile`, `analyze_function_complete`, `read_memory`, xrefs/callers, `get_function_by_address`; context W37-T untrack + `TFID_EqualsObjectId`. **No** `disassemble_bytes` |
| **Verdict** | **accept-with-gaps** — CF/ABI/`ret 4`/dual-mode match sealed; product payload English open |
| **Dual status** | **Present (W38-S)** |

---

## 1. Purpose

**Match** a track-list **payload** to a target **object**:

```
// __thiscall payload; stack (object*); ret 4; bool AL
if (payload.tfid fully invalid && object.tfid fully invalid)
  return payload.objectBackPtr (+0x10) == object;
else
  return payload.tfid {+0x18,+0x1c,+0x20} == object.tfid@ (object+adj+0x164);
```

Primary consumers (W37-T sealed): 9-bucket untrack `FUN_004bfd10` and sibling flag-set `FUN_004bfdb0`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | Ghidra `batch_decompile` `0x005c6720` (2026-08-04) |
| Complete analysis | 2 CODE xrefs; callers `FUN_004bfd10`, `FUN_004bfdb0`; leaf |
| Machine | `read_memory` @ `0x005c6720` length 128 → body **104 B** then `CC` |
| Peer TFID | `TFID_EqualsObjectId` @ `0x00404aa0` (same 9-byte field set) |
| Parent use | W37-T `TrackMgr_9CircList_UntrackObject_Inferred` |
| Scaffold | `raw/aa_005c6720_*`, `reconstructed-exact/FUN_005c6720.cpp` |

**Not performed:** Launcher, runtime golden, dual of object TFID layout producer, parent ledger edits.

---

## 3. Machine seal (`read_memory`)

| Claim | Evidence | Conf |
|---|---|---|
| `mov eax,[ecx+0x18]; and eax,[ecx+0x1c]; cmp eax,-1` | invalid gate on payload | **Confirmed** |
| Object load `mov eax,[esp+4]` | stack object* | **Confirmed** |
| Object TFID via `[eax+4]→[+4]` then `[edx+eax+0x164]` | MI adj + fixed `0x164` | **Confirmed** |
| Invalid pair → `cmp [ecx+0x10],eax; setz dl` | pointer identity | **Confirmed** |
| Else compare lo/hi/byte@+8 vs payload +0x18/+0x1c/+0x20 | TFID triple | **Confirmed** |
| All exits `ret 4` (`c2 04 00`) | ABI | **Confirmed** |
| Body 104 B exclusive end `005c6788` | hex count + pad `CC` | **Confirmed** |

Full hex (104 B):

```
8b411823411c83f8ff8b44240475288b50048b5204568bb4026401000023b4026801000083feff5e750d33d23941100f94c28ac2c204008b50048b52048d8402640100008b103b511875188b50043b511c75108a40083a41207508b801000000c2040033c0c20400
```

---

## 4. Layout contract

### Payload

| Offset | Role |
|---|---|
| `+0x10` | object* (identity fallback) |
| `+0x18` | TFID lo |
| `+0x1c` | TFID hi |
| `+0x20` | TFID global (byte) |

### Object TFID

| Formula | Role |
|---|---|
| `adj = *(*(object+4)+4)` | MI / base adjustment |
| `object+adj+0x164` | TFID base (lo@0, hi@4, global@8) |

Invalid test: `(lo & hi) == 0xFFFFFFFF` (both dwords all-ones).

---

## 5. Callers / callees

| Direction | Detail |
|---|---|
| Callees | none |
| Callers | `004bfd10` untrack; `004bfdb0` set `+0x51` |
| Call shape | `mov ecx,payload; push object; call` (bytes sealed in W37-T A) |

---

## 6. Confidence table

| Claim | Level |
|---|---|
| Dual-mode match CF | **Confirmed** |
| `__thiscall` + `ret 4` + bool | **Confirmed** |
| TFID 9-byte fields | **Confirmed** (peer `00404aa0`) |
| Role = track payload match | **High** |
| Product payload class name | **Open** |
| Product meaning of `*(object+4)` | **Tentative** (formula sealed) |

---

## 7. Gaps

1. Product English for payload / track entry type.  
2. Full object type owning TFID at `+adj+0x164`.  
3. Runtime / differential.

**Verdict:** **accept-with-gaps**
