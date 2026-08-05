# Review B (skeptical / adversarial): `aa_0053fff0` Mission_EnsureRegionMissions

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053fff0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (wave3 seal: `+0xf18` wrapper) |
| **Counterpart** | `reviews/A_aa_0053fff0_Mission_EnsureRegionMissions.md` |
| **Verdict** | **accept** — falsifies “returns hash” / free-nullary myths; seals wrapper |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | `FUN_0053fff0()` is free / nullary and returns the mission **hash** | Live: `ECX=owner`; returns `*(owner+0xf18)` **wrapper\***; hash is `*wrapper` | **Falsified** as hash return |
| 2 | Slot is raw `CNDHash*` at `+0xf18` | Ctor builds **0x10** object with **four** hash pointers; primary is `[0]` | **Falsified** |
| 3 | Getter loads/parses mission DB itself | Populate is inside `FUN_0060b870` only on first ensure | **Falsified** for getter body |
| 4 | `operator_new` failure leaves garbage | `xor eax,eax` then store → null | **Falsified** |
| 5 | All four hashes are identical CNDHash | `[0]`/`[1]` 0x34 distinct vtbls; `[2]`/`[3]` 0x38 + alt vtbl | **Partially falsified** — same family, not identical |
| 6 | Product name is unknown forever | Ctor path string **`VOGRegionMissions.cpp`** + OOM `"missions!"` | **Class High**; method English open |
| 7 | `DAT_00b041fc` is the only owner | Callers also use `*(ctx+0xd30)` etc. | **Falsified** as sole owner |
| 8 | Secondary keys sealed by this unit | `FUN_0060c010` this-ptr not recovered in decompile | **Residual** — do not invent |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Lazy slot `owner+0xf18` | **High** | Wrong global / double-init |
| Return = wrapper\*, need `*wrapper` for id lookup | **High** | Null hash / crash on lock |
| Primary hash = `wrapper[0]` via `FUN_0053b0b0(8)` | **High** | Wrong table walked |
| Objective-side hash = `wrapper[1]` | **High** layout / **Probable** gloss | Miss objective index |
| `[2]`/`[3]` key domains | **Tentative** | Wrong secondary filters |
| Class `CVOGRegionMissions` | **High** (path) | Naming only |
| Method English | **Open** | Docs only |

---

## 3. Cross-check against raw + bytes

```
0053fff0:
  mov esi, ecx                 ; owner
  cmp dword [esi+0xF18], 0
  jnz already
  push 0x10 / call operator_new
  test eax / jz null
  mov ecx, eax / call FUN_0060b870
  mov [esi+0xF18], eax         ; (null path stores 0)
already:
  mov eax, [esi+0xF18]
  ret (after SEH teardown)
```

Raw pseudocode matches. Ctor raw:

- Four stores to `param_1[0..3]`
- Source `VOGRegionMissions.cpp`
- Insert `FUN_0053c360` / `FUN_0053c460` / `FUN_0060c010`

---

## 4. Surviving contract for AutoCore

```
// Never treat EnsureRegionMissions return as CNDHash*
wrapper = Mission_EnsureRegionMissions(owner);  // owner typically g_pMissionOwner / DAT_00b041fc
if (!wrapper) return fail;
hash = *(CNDHash**)wrapper;   // primary mission-id table
// lock hash+0x1d, LookupByKey / walk +0x14, unlock
```

Server parity: mission **definitions** are data-driven (DB/WAD → region missions tables). This client unit is the **lazy table root**, not grant/complete authority.

---

## 5. Falsified prior / casual language

| Phrase | Correct |
|---|---|
| “`FUN_0053fff0` returns hash” | Returns **wrapper**; hash = `*wrapper` |
| “lazy hash at +0xf18” | Lazy **wrapper** at +0xf18; hash inside |
| “mission table root object is CNDHash” | Root is **4-hash holder** (`CVOGRegionMissions`) |

---

## 6. Open questions

1. Method product name on the owner class.
2. Owner type of `DAT_00b041fc`.
3. Which wrapper slot is `this` for each `FUN_0060c010` call; keys `+0x88` / `+0x86` English.
4. Whether `[2]`/`[3]` are region/continent secondary indexes (likely, unsealed).
5. Lifetime / destroy path for `owner+0xf18` (out of unit).

**Verdict:** **accept** — wrapper seal holds under adversarial review.
