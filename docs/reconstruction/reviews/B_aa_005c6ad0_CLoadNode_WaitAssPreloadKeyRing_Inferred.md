# Review B (skeptical / adversarial): `aa_005c6ad0` CLoadNode_WaitAssPreloadKeyRing_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c6ad0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W36-F) |
| **Counterpart** | `reviews/A_aa_005c6ad0_CLoadNode_WaitAssPreloadKeyRing_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX is the GuardedVector ring | **Falsified** — ring is stack/`EDI`; ECX is load-node host (caller `MOV ECX,EDI` node this; push ring) |
| 2 | `CONCAT31` mutates the ring pointer to flag=1 | **Falsified** — stack-slot reuse artifact; ring stays EDI; separate byte set to 1 before ProcessKeyRingStep |
| 3 | Return 1 means done (like ProcessKeyRingStep AL) | **Falsified** — this unit returns **0** ready / **3** wait (CLoadNode stage codes) |
| 4 | Always ExpandDeps every call | **Falsified** — only when counter not in [1,6] and AssPreloader non-null |
| 5 | Blocking full preload | **Falsified** — single ProcessKeyRingStep; yield 3 to parent |
| 6 | Scaffold `Named_CalleeOf_*` product name | **Rejected** |
| 7 | Empty check is `!= 0` signed only | **Minor** — bytes `JBE` after cmp size,0 (unsigned ≤0); non-negative size family |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX host + stack ring + RET 4 | **High** | Wrong this / stack |
| EAX 0/3 stage codes | **High** | Infinite stage loop |
| Counter band + cursor fields | **High** | Stuck wait / missed expand |
| ExpandDeps AssPreloader this | **High** | Crash |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | Preload races |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  if size==0: counter=0; return 0
  if counter∉[1,6]: maybe reset; ExpandDeps if preloader
  flag=1; step=ProcessKeyRingStep(ring,&flag,&cursor)
  if step==0: counter++; return 3
  counter=0; return 0

bytes (110 B): full hex sealed
caller _initPreload: PUSH ring@+0x174; MOV ECX,node; CALL; CMP EAX,3 → wait
```

Live ≡ raw CF; **bytes win** on ABI and ExpandDeps this.

---

## 4. Surviving contract for AutoCore

```
// CLoadNode coop wait on AssPreload key ring:
//   ECX = load-node host (counter@+0x54, cursor@+0x5c)
//   stack = GuardedVector* ring; RET 0x4
//   EAX = 0 ready / 3 wait
//   empty ring → ready
//   counter outside 1..6 → optional ExpandDeps(AssPreloader, ring)
//   one ProcessKeyRingStep with progress_flag=1
// Do NOT pass ring in ECX.
// Do NOT treat return as AL 0/1 from ProcessKeyRingStep alone.
// Do NOT invent product plate from Named_CalleeOf scaffold.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/returns and rejects ring-as-this / CONCAT31 / AL-return / always-expand claims → **accept-with-gaps**.
