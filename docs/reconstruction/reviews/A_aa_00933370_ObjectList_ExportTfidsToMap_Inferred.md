# Review A (reconstruction fidelity): `aa_00933370` ObjectList_ExportTfidsToMap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00933370` |
| **VA** | `0x00933370` |
| **Canonical name** | `ObjectList_ExportTfidsToMap_Inferred` |
| **Prior names** | `FUN_00933370`, `Named_CalleeOf_Named_VOGClient_00933370` |
| **Review date** | `2026-07-29` (dual A/B — OWN-ONLY) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_00933370_ObjectList_ExportTfidsToMap_Inferred.md` |
| **System** | client world / VOG list export |
| **Dual status** | **Present** (first dual pair) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Export every live object from a **list host** into a temporary **keyed map/set** (TFID + cbid + object*):

```text
// ECX = list host (int* with vtbl)
if host == 0: return
sentinel = FUN_0040fb90()          // empty std-list/map head
host.vtbl[+0x2b0](&out_list)      // materialize iteration list into local_34
for node in circular list:
  obj = node[2]
  if obj:
    pack = { obj, cbid=*(obj+0xa8)+0x34, tfid_lo=obj+0x160, tfid_hi=obj+0x164, list_head }
    FUN_00406040(&map_stack, &pack)  // insert into map
// clear list links; operator_delete nodes / head
```

Callers in client VOG paths (`FUN_00943b80`, `FUN_009440e0`) use the map for subsequent TFID-keyed work (nearby interact / floater / select).

---

## 2. Calling convention

| Slot | Role | Evidence |
|------|------|----------|
| **ECX** | List host* | Callers `mov ecx, eax/esi` before call; decompiler `__fastcall` |
| Stack | possible extra (some sites `PUSH EDI`) | Context shows push before call — may be callee-unused or parent frame |
| Return | `void` (teardown always) | |
| SEH | `LAB_009ad3cd` | Prologue |

Live prologue:

```text
00933370  push -1
00933372  mov  eax, fs:[0]
00933378  push LAB_009ad3cd
…
0093338a  sub  esp, 0x30
0093338d  push ebx
0093338e  push ebp
0093338f  mov  ebp, [esp+0x48]   ; SEH-adjusted stack arg residual
```

Decompiler models primary as **ECX this**; call sites confirm `mov ecx, …`. Stack `PUSH EDI` at some sites is parent context / optional second arg — body CF does not consume a second semantic input beyond the vtbl list pull.

---

## 3. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean / record | `aa_00933370_*` |
| Live decompile | Ghidra `batch_decompile` `0x00933370` |
| Live bytes | `read_memory` length 32 |
| Callers | `FUN_00943b80` @ `0x00943d44`, `FUN_009440e0` @ `0x0094444f`, `0x0094475e` |
| Callees | `FUN_0040fb90` (empty list), `FUN_00406040` (map insert), `operator_delete` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null host early out | **Yes** |
| Alloc empty sentinel list | **Yes** |
| `vtbl+0x2b0` fill | **Yes** |
| Walk circular list `node→next` until head | **Yes** |
| Pack TFID (`+0x160/+0x164`) + cbid (`*(+0xa8)+0x34`) + obj* | **Yes** |
| `FUN_00406040` insert | **Yes** |
| Unlink + delete list storage | **Yes** (decompiler dual `operator_delete` paths noisy but teardown intent clear) |

### Object field pack

| Source | Role |
|--------|------|
| `obj+0x160/+0x164` | TFID halves |
| `*(obj+0xa8)+0x34` | CBID from clonebase |
| `obj*` | payload pointer in map node |

---

## 5. Naming / gaps

| Claim | Confidence |
|---|---|
| Role = list → TFID map export | **High** |
| ECX list host | **High** |
| `FUN_00406040` exact map type | **Probable** |
| Decompiler noreturn delete warning | **Noise** — paths still free nodes |
| Runtime | **Open** |

---

## 6. Verdict

**accept-with-gaps** — export walk and TFID/cbid pack sealed; map type English residual.
