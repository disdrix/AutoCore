# Review B (skeptical / adversarial): `aa_00545a90` CNDHash_Insert

| Field | Value |
|---|---|
| **Stable ID** | `aa_00545a90` |
| **VA** | `0x00545a90` |
| **Canonical name** | `CNDHash_Insert` (vtbl `009d01ac`) |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00545a90_CNDHash_Insert.md` |
| **System** | container / missions-progression |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `softIfExists` allows multi-node same key | Soft path returns 1 **without** linking | **Falsified** multi-map |
| 2 | Lock aborts insert | Logs then continues | **Falsified** hard abort |
| 3 | Same VA as mission `0053c560` | Different address + vtbl `009d01ac` vs `009cefd4` | **Falsified** merge |
| 4 | This loads `//tContinentObject/row` | Loader is `007dbce0`; this only inserts | **Falsified** loader claim |
| 5 | `operator_new` for nodes | `FUN_0053ada0` freelist | **Falsified** |
| 6 | Returns void / bool only | HRESULT-style 0 / 1 / 0x80004003 / 0x80004005 | **Falsified** |
| 7 | `ret 8` (two stack args) | Bytes **`C2 0C 00`** → three stack args | **Falsified** wrong ret |
| 8 | Known caller always soft | `00541950` passes soft **0** | **Agree** hard-dup path |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert CF + HRESULT codes | **Confirmed** | Wrong error handling |
| Soft vs hard policy | **Confirmed** | Multi-insert bug |
| ret 0xc / thiscall | **Confirmed** | Stack imbalance |
| Vtbl 009d01ac distinct twin | **High** | Wrong node dtor |
| Continent loader consumer | **High** | Wrong hash population |
| Freelist details | **Open** | Pool desync |
| Runtime | **Open** | |

---

## 3. Cross-check against raw / live / twins

```
raw/clean ≡ batch_decompile (2026-07-29).
bytes @ 0x00545a90:
  cmp [esp+0xc], ebx     ; value
  jz -> mov eax,80004003; ret 0xc
  cmp byte [edi+0x1d],0  ; lock
  ...
  call CNDHash_LookupByKey ×2
  call FUN_0053ada0
  mov [node], PTR_FUN_009d01ac

Twin CF family (do not merge sites):
  0053c360, 0053c460, 0053c560, 0053c660, 0053c760, 00413920 (u64), 0051e6d0, ...
```

### Soft-flag trap

```
soft!=0 && hit -> return 1   // no mutation
soft==0 && hit -> E_FAIL
```

Not “insert another node.”

### Twin trap

Redirecting mission insert sites to `0x00545a90` (or reverse) links nodes with the **wrong vtbl**. Continent table install owns **`009d01ac`**.

### Ownership trap

`007dbce0` loads rows; **`00545a90` only hashes them**. Do not invent load logic here.

---

## 4. Surviving contract for AutoCore

```
CNDHash_Insert_00545a90(hash, key, value, softIfExists) -> int
  value==null         -> 0x80004003
  soft && hit         -> 1
  !soft && hit        -> 0x80004005
  else                -> node vtbl 009d01ac, bucket+list link, count++, 0

// lock+0x1d: warn only

Caller: FUN_00541950 after Mission_tContinentObject load
  key = *(uint32*)row; value = row; soft = 0

AutoCore must NOT:
  - multi-insert on soft flag
  - hard-fail on lock without continuing
  - merge with other CNDHash_Insert VAs
  - malloc nodes outside freelist
  - treat this as the table loader
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Twin insert CF + vtbl 009d01ac | **Agree Confirmed/High** |
| Soft=return 1 / hard=E_FAIL | **Agree Confirmed** |
| Lock log-only | **Agree Confirmed** |
| Continent consumer 00541950 | **Agree High** |
| accept-with-gaps | **Agree** |

---

## 6. Open questions

1. Full `009d01ac` method dual (dtor/value free).
2. Hash field offset on the parent object in `00541950`.
3. Runtime duplicate-key behavior on re-load.

**Verdict:** **accept-with-gaps** — agree with A; block soft-multi, VA merge, and loader/insert ownership confusion.
