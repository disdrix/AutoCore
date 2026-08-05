# Review A (reconstruction fidelity): `aa_0092a200` Object_MatchesFilterDescriptor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092a200` |
| **VA** | `0x0092a200` |
| **Canonical name** | `Object_MatchesFilterDescriptor_Inferred` |
| **Prior names** | `FUN_0092a200`, `Named_CalleeOf_Client_CreateVehicleObjectApply_0092a200` |
| **Review date** | `2026-07-29` (dual A/B — OWN-ONLY) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_0092a200_Object_MatchesFilterDescriptor_Inferred.md` |
| **System** | `interaction-activation` / inventory-create filters |
| **Dual status** | **Present** (first dual pair) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Boolean **predicate**: does world/inventory **object (EBX)** match a **filter descriptor (EAX)**?

```text
// EAX = filter descriptor, EBX = candidate object
if EBX==0: return 0
def = object.vtbl+0x1d8()
if def && (def+0x210 & def+0x214) != 0xffffffff: return 0   // reject flagged def

// Pass A — type-id table at filter+0xac count, keys at +0xb0:
for i in 0..count-1:
  if object.vtbl+0x28c() == filter.typeIds[i]:
    mapped = filter+0xd8[i]   // parallel map (category / subtype)
    if mapped == -1: return 1
    if mapped != object.clonebase+0x38: return 0
    // optional level band via object.vtbl+0x27c vs filter+0x108 / +0x10c (-1 = open)
    return level_ok ? 1 : 0

// Pass B — race/class table: require object.vtbl+0x1d4(); compare def+0x14c to filter+0x80 keys
//          same optional level band → 1

// Pass C — CBID allow list filter+0x28 / +0x2c: object.clonebase+0x34
// Pass D — second CBID list filter+0x54 / +0x58
// Pass E — exact TFID: if (filter+0x20 & filter+0x24) != -1 and equals object TFID [0x58]/[0x59]
return 0
```

Callers set **`*(filter+4)=1`** when AL true (match latch). Used from `Client_CreateVehicleObjectApply`, inventory apply paths, and client UI ticks.

---

## 2. Calling convention — **SEALED**

| Slot | Role | Evidence |
|------|------|----------|
| **EAX** | Filter descriptor* | Prologue `mov esi, eax`; sites `mov eax, [obj+0x4d0]` / table ptr |
| **EBX** | Candidate object* | Prologue `test ebx,ebx`; sites `mov ebx, edi/esi` |
| **AL** | bool match | `test al,al` after call |
| Stack | none | Plain `ret` |

Live prologue (`read_memory` `0x0092a200`):

```text
0092a200  test ebx, ebx
0092a202  push esi
0092a203  mov  esi, eax
0092a205  jz   fail
0092a207  mov  eax, [ebx]
0092a209  mov  ecx, ebx
0092a20b  call dword [eax+0x1d8]
```

---

## 3. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean / record | `aa_0092a200_*` |
| Live decompile | Ghidra `batch_decompile` `0x0092a200` |
| Live bytes | `read_memory` length 32 |
| Callers | `Client_CreateVehicleObjectApply`, `FUN_0080af70`, `FUN_00811e00`, `FUN_00919dc0`, `FUN_0092a3b0`, `FUN_009440e0`, `FUN_00945540` |
| Call-site pattern | match → `mov byte [filter+4], 1` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null EBX → 0 | **Yes** |
| Def flag mask reject | **Yes** |
| Type table + parallel map `+0xd8` | **Yes** |
| Level min/max `+0x108`/`+0x10c` (−1 open) | **Yes** |
| Secondary race/class table `+0x80` | **Yes** |
| Two CBID lists `+0x28`, `+0x54` | **Yes** |
| Exact TFID `+0x20/+0x24` vs object `[0x58]/[0x59]` | **Yes** |
| Default 0 | **Yes** |

### Filter descriptor offsets (body-backed)

| Offset | Role |
|--------|------|
| `+0x20/+0x24` | optional exact TFID (and mask pair) |
| `+0x28` count / `+0x2c` CBID[] | allow list A |
| `+0x54` count / `+0x58` CBID[] | allow list B |
| `+0x80` count / `+0x84` keys | race/class pass |
| `+0xac` count / `+0xb0` type ids | primary type pass |
| `+0xd8` | parallel mapped subtype per type entry |
| `+0x108` / `+0x10c` | level min / max (−1 = none) |

Object: `clonebase` at `object[0x2a]` (`+0xa8`); type at clonebase `+0x38`; cbid `+0x34`; TFID at object dword indices `0x58/0x59`.

---

## 5. Naming / gaps

| Claim | Confidence |
|---|---|
| Role = multi-table object filter predicate | **High** |
| EAX=filter, EBX=object, AL=bool | **High** |
| Canonical name | **Probable** |
| Product field names for each table | **Tentative** |
| Runtime | **Open** |

---

## 6. Verdict

**accept-with-gaps** — ABI and five-pass CF sealed from live bytes + multi-caller sites.
