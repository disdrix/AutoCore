# Review B (skeptical / adversarial): `aa_00518cf0` Skill_LookupActiveCastBinding

| Field | Value |
|---|---|
| **Stable ID** | `aa_00518cf0` |
| **VA** | `0x00518cf0` |
| **Canonical name** | `Skill_LookupActiveCastBinding` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` (dual residual strengthen `2026-07-29`; ABI/ECX re-seal same day) |
| **Counterpart** | `reviews/A_aa_00518cf0_Skill_LookupActiveCastBinding.md` |
| **Residual scratch** | `reviews/a_00518cf0.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Creates / always installs binding | Body is get+find+copy only | **Falsified** |
| 2 | No empty / unbound path | Miss arm copies invalid TFID | **Falsified** |
| 3 | Out is opaque multi-field bind struct | Only 4 dwords copied; callers treat as TFID | **Falsified** (out = TFID16) |
| 4 | `DAT_00a15870` is the active-cast map | Map is `FUN_00518c20` → `owner+0x68`; A15870 is invalid TFID twin | **Falsified** |
| 5 | Body starts cast-again HB when unbound | HB is caller-side (`RequestCast` / Stance) | **Falsified** as body duty |
| 6 | `FUN_00518c20(pTmp, key)` is a 2-arg map API | Unary `__fastcall`; stack pushes feed `FUN_0051c150` (body bytes) | **Agree noise Confirmed** |
| 7 | Key is not skill id | Find helper keys `node+0x10`; callers pass `skill+0x5fc` | **Attack fails** — key = skill id **Confirmed** |
| 8 | Node `+0x20` only “tentative” / truncated TFID | All four dwords `+0x18…+0x24` written | **Attack fails** — full TFID16 **Confirmed** |
| 9 | Exclusive LocalCastValidate helper | 8 callers / 9 sites | **Falsified** exclusive use |
| 10 | Pure stack `__stdcall` with no register owner | Prologue `mov esi,ecx`; ESI → both map gets | **Attack fails** — **ECX = mapOwner Confirmed** |
| 11 | Ghidra `__stdcall` is tool fiction | Both epilogues `C2 08 00` (`ret 8`) | **Attack fails** — stack cleanup **Confirmed** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Out TFID16 fill (hit + miss) | **Confirmed** | False busy/free / sticky gates |
| Map key = skill id (`node+0x10`) | **Confirmed** | Wrong bind slot |
| Find exactness (lb + `<=`) | **Confirmed** | Spurious hit on wrong node |
| End = `*(map+4)` | **Confirmed** | Hit/miss inversion |
| Miss sentinel `9CDF88` bytes | **Confirmed** | Compare mismatch vs callers using `A15870` |
| `9CDF88` ≡ `A15870` static | **Confirmed** image | Runtime diverge residual risk **Low** |
| Map shell `FUN_00518c20` / `+0x68` | **Confirmed** (sibling) | Wrong subsystem |
| Entry ECX = mapOwner | **Confirmed** | Wrong object for map slot |
| Map owner product type | **Open** | Port to wrong object class |
| `__stdcall` `ret 8` | **Confirmed** (bytes) | ABI mismatch in hooks (risk closed) |
| Plate “HB only when unbound” as body | **Unsafe** | Over-claim on this VA |

---

## 3. Cross-check against raw / live / bytes

```
raw/clean/live: get map → find skillId → copy value TFID16 or invalid sentinel.
Body bytes: mov esi,ecx; push &key; push &it; call get-map; mov ecx,eax; call find;
            call get-map; cmp it,[map+4]; hit copy+0x18 / miss load 9CDF88; ret 8.
Decompiler FUN_00518c20 multi-arg at first site: noise Confirmed (args for find).
Live ≡ raw CF for hit/miss arms: Yes (2026-07-29 re-decompile + body read_memory).
```

### Sentinel trap

Prior A listed “DAT_00a15870 map identity” as an open gap. That framing is wrong:

- **Map** = result of `FUN_00518c20` (header `_Myhead` @ `+4`, size @ `+8`).
- **`0x00a15870`** = `g_abTfidInvalid_A15870`, parallel invalid TFID (same static bytes as `9CDF88`).
- Body **writes** `9CDF88` on miss; many **callers compare** against `A15870`. Do not merge symbols into one “map global”.

### ABI trap

Ghidra signature lists only stack formals. **Attackers / hook authors must also set ECX = map owner** (host with `+0x68` map). Omitting ECX is not a “pure stdcall” of two stack args alone.

---

## 4. Surviving contract for AutoCore

```
LookupActiveCastBinding(mapOwner_ECX, outTfid16, skillId):  // ret 8
  // shared cast-lock query (read-only)
  map = lazy ActiveCastBindingMap shell (FUN_00518c20 @ owner+0x68)
  it  = map.find(skillId)                 // FUN_0051c150; key node+0x10
  if it != map.end:                       // end = *(map+4)
    out = it.value.tfid16                 // node+0x18..+0x24
  else:
    out = InvalidTfid                     // g_abTfidInvalid_9CDF88

Consumers:
  LocalCastValidate  — proceed skill gates only when out == invalid
  RequestCastSkill   — cast-again HB / FX only when out == invalid (caller)
  ResolveCastTarget  — sticky form bit: out != invalid → silent invalid list
  Clear path sibling — Skill_ClearCastBindingAndMaybeRestartCd (mutate; not this VA)
```

Port note: server authority must not trust client binding map; this is **client-local** cast bookkeeping.

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Out TFID16 sealed | **Agree Confirmed** |
| Miss = `9CDF88` only | **Agree** |
| A15870 is not map | **Agree** (falsify prior gap) |
| Map via `FUN_00518c20` | **Agree Confirmed** |
| Find via `FUN_0051c150` | **Agree Confirmed** |
| Exact key match | **Agree Confirmed** (find filter) |
| Read-only | **Agree** |
| Caller inventory 8/9 | **Agree Confirmed** (xrefs) |
| `ret 8` / entry ECX | **Agree Confirmed** (body bytes) |
| Map owner product open | **Agree** — do not invent “character+0x68” without owner seal |
| accept-with-gaps | **Agree** |

---

## 6. Open questions

1. Seal map **owner product type** (with `FUN_00518c20` / `GetCategoryCooldownMap` twin residual). Register role already sealed.
2. Name or leave-FUN `FUN_0051c150` on string/RTTI evidence only.
3. Clear-path node field semantics if they diverge from pure TFID16 value (ownership of Clear unit).
4. Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — agree with A residual seals (including ABI/ECX upgrade); block over-claims on map-global symbol, body-owned HB policy, and map-owner class name.
