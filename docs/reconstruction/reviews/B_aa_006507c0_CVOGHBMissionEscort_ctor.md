# Review B (skeptical / adversarial): `aa_006507c0` CVOGHBMissionEscort_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_006507c0` |
| **VA** | `0x006507c0` |
| **Canonical name** | `CVOGHBMissionEscort_ctor` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_006507c0_CVOGHBMissionEscort_ctor.md` |
| **System** | missions-progression / heartbeat |
| **Live tools** | Independent decompile + `read_memory` + RTTI/vtable/caller decompiles |
| **Verdict** | **accept-with-gaps** — accept Escort ctor; reject Outpost / void / wrong RET / non-ctor naming |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is `CVOGHBOutpost` (nearby `"outpost"` @ `0x009e52a4`) | **Falsified** — RTTI TD is `.?AVCVOGHBMissionEscort@@`; Outpost is separate class |
| 2 | Not a constructor (just a rebind helper) | **Falsified** — `CVOGHBBase_ctor` + first vtable write + factory `operator_new(0x78)` |
| 3 | `void` return / no this return | **Falsified** — `mov eax,esi` before `ret 8` |
| 4 | `ret 4` (one stack arg only) | **Falsified** — exit `C2 08 00` |
| 5 | Period stays −1000 from SetPeriod | **Falsified** — immediate store `*(this+8)=1000` after Attach |
| 6 | TFID pad is zero-init only | **Falsified** — loads `DAT_009e52b0..bc` = `{−1,−1,0,0}` |
| 7 | OnHeartBeat is not this class | **Falsified** — same vtable slot `+0x0C` dualed as Escort OnHB |
| 8 | Scaffold Named_CalleeOf product name | **Rejected** |
| 9 | Full dual of reqHost schema as product English | **Open** — offsets High; labels Probable |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Escort RTTI + vtable | **High** | Wrong HB subclass port |
| Ctor CF / ABI | **High** | Stack imbalance / missed fields |
| Field offset map vs OnHB | **High** | Escort fail/complete broken |
| Second factory at `00613e62` | **Medium** | Missed spawn path |
| Product field English | **Probable** | Mislabel docs only |
| Runtime | **Open** | |

---

## 3. Decompiler pitfalls (must survive port)

1. Keep **`ret 8`** (two stack args) — decompiler may omit cleanup.
2. Do not treat `FUN_0060c3c0` as optional decoration — fills match ref when `req+0x44==-1`.
3. Preserve period pattern: SetPeriod(−1000,true) **then** force `+0x08=1000`.
4. Do not bind `"outpost"` litter near vtable data as class evidence.
5. Factory size **0x78** is from caller, not ctor body.

---

## 4. What is safe to claim

| Safe | Unsafe |
|---|---|
| Escort ctor installs `PTR_FUN_009e52c4` | PDB method spelling beyond RTTI |
| Field seed offsets used by dualed OnHB | Full product names for every req offset |
| Primary factory `FUN_0060c860` | Semantics of gap call site without function |
| Client-only HB action construction | Server authority for escort completion |

---

## 5. CF challenge of Review A

- RTTI + vtable + ABI: **agree Confirmed/High**
- Field map alignment with OnHB: **agree High**
- accept-with-gaps for English + gap call site: **agree**

**Verdict:** **accept-with-gaps**
