# Review B (skeptical / adversarial): `aa_00943520` Client_SelectNearestHostileInRange_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00943520` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_00943520_Client_SelectNearestHostileInRange_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same as screen hostile pick (`00921f70`) | No unproject/ray; fixed stack range; no select(0) clear | **Falsified** merge |
| 2 | Same as cycle hostile (`00943340`) | No list buffer of 50; no index walk; maxTargets 1 only | **Falsified** merge; **survives** as nearest peer |
| 3 | Mode is ally (1) not hostile (2) | Push `6A 02`; mode table dual lists this VA under mode 2 | **Falsified** ally |
| 4 | `__thiscall` ECX-this | Prologue `MOV ESI,EAX`; callers `MOV EAX, client` | **Falsified** ECX-this; **survives** EAX-this |
| 5 | Always sorts by distance | Pass 2 sets sort=0 if pass 1 empty | **Falsified** always-sort |
| 6 | Clears selection on miss | Double-invalid → bare return | **Falsified** clear-on-miss |
| 7 | Range hard-coded 110 inside body | Body uses stack `param_1`; 110 is **caller** literal | **Falsified** body constant; **survives** poll convention |
| 8 | Gather self-allow matters for mode 2 | Mode table: self flags ignored for mode 2 | **Survives** as literal still pushed; **no** self-accept effect |

---

## 2. Live ≡ raw ≡ bytes

Live decompile matches raw 2026-07-23. Body end `C2 04 00`. Call targets sealed: Resolve `004bb950`, Select `0093e120`. Invalid bank `00a15870` = `FFFFFFFFFFFFFFFF 0000000000000000`.

Xrefs: 3 in `Client_Input_PollBoundActions` + 1 orphan `00925467`.

---

## 3. Surviving contract

```
// EAX = client
// stack float rangeArg; RET 4
// if char+0x4f1: return
// origin = MI(char)->vtbl[0x1a0]()
// seed invalid TFID
// Gather(mode=2, max=1, sort=1, score=-1, range=arg, ...)
// if invalid: Gather(... sort=0)
// if invalid: return
// ECX = *(*(char_comp+0xa8)+0xe4e8); obj = Object_ResolveFromTFID(&tfid)
// if obj: Client_SelectTargetObject(obj)
```

**Gaps kept:** product keybind names; `+0xa8` product type; orphan site function; runtime.

**Verdict:** **accept-with-gaps**.
