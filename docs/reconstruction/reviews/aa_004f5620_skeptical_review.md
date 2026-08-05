# Skeptical / adversarial review: `VehicleEntity_SetSteerInput` @ `0x004f5620`

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f5620` |
| **Review type** | Skeptical / adversarial (try to falsify current interpretation) |
| **Date** | 2026-07-23 |
| **Scope** | Gate+store unit and claims attached to it across RE artifacts |
| **Verdict** | **needs-more-evidence** |

**Generic approval is insufficient.** This review is not a rubber stamp. Concrete checks performed are listed in §8. Claims that survive are those that survived *attack*, not those that were merely restated.

---

## 1. What was inspected

### Primary unit artifacts (required)

| Path | Role |
|------|------|
| `docs/reconstruction/raw/aa_004f5620_VehicleEntity_SetSteerInput.md` | Immutable decompile capture |
| `docs/reconstruction/raw/aa_004f5620_VehicleEntity_SetSteerInput.annotated.md` | Widths / CF / side-effect notes |
| `docs/reconstruction/reconstructed-exact/VehicleEntity_SetSteerInput.cpp` | Exact C++ port surface |
| `docs/reconstruction/functions/aa_004f5620_VehicleEntity_SetSteerInput.md` | Function record + confidence table |
| `docs/reconstruction/systems/input-drive-control.md` | Caller system map (DriveControlTick) |
| `docs/reconstruction/physics/verified/fn_004f5620_setSteerInput.md` | Prior “verified” physics note |
| `docs/reconstruction/OBJECT_LAYOUTS.md` | Entity / lock-object layout claims |
| `docs/reconstruction/experiments/vehicle_entity_set_steer_input.py` | Pure Python behavioral model |

### Cross-check / attack surfaces (used to try to break claims)

| Path | Why |
|------|-----|
| `docs/reconstruction/physics/drive-controller-spec.md` | Inline NPC gate + steer sign from `lateral` |
| `docs/reconstruction/physics/verified/fn_steering_input_feed.md` | Downstream identity of `entity+0x618` |
| `docs/reconstruction/physics/verified/fn_entity_driveAxes_offsets.md` | Writer/consumer map for `+0x614/+0x618/+0x61c` |
| `docs/reconstruction/physics/steering-spec.md` | applyAction stage-1 uses `entity+0x618` as ramp target |
| `docs/reconstruction/types/VehicleEntity_drive_axes.md` | Type-level gate restatement |
| `docs/reconstruction/NAMING_REGISTRY.md` | Overconfident name inventory |
| `docs/reconstruction/UNRESOLVED_FINDINGS.md` | Open gaps already admitted |
| Sibling raw | `raw/aa_004f5650_VehicleEntity_SetLongitudinalInput.md` (gate parity claim) |

**Not performed this review:** fresh Ghidra re-decompile, instruction dump, CE/runtime, or live flag-bit producers. That absence is intentional evidence *against* sealing semantics, not a free pass for the existing narrative.

---

## 2. Evidence used

### A. Authoritative body (raw capture)

```c
iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1);
if ((iVar1 == 0) || ((*(byte *)(iVar1 + 0xb4) & 199) == 0)) {
  *(undefined4 *)(param_1 + 0x618) = param_2;
}
return;
```

Mechanical consequences from this alone:

1. Three pointer loads; final slot is entity-relative: `*(p1 + this + 0xb0)`.
2. Branch is `wobj == 0 || (byte_flags & 199) == 0` → store; else retain prior.
3. `199` decimal = `0xC7` = bits `0x01|0x02|0x04|0x40|0x80`.
4. Flag load is **byte**, not dword.
5. Store is raw 4-byte bit pattern to `this+0x618` (typed `undefined4`; no FP ops).
6. No calls, no other stores, no clamps.

### B. Sibling parity

Longitudinal setter @ `0x004f5650` uses **identical** gate and chain; only store target differs (`+0x614`). That strengthens “shared axis-write suppress,” not “steer lock.”

### C. Downstream identity of `+0x618`

Multiple independent consumers treat `entity+0x618` as the raw steer command:

- `VehicleAction_applyAction` stage-1: `delta = entity[0x618] - VA[0x24]` (`steering-spec.md`, `fn_steering_input_feed.md`).
- PushDriveAxes deliberately does **not** copy `+0x618` (thr/HB only) — steer stays on entity for applyAction.
- AI `MoveToTarget3DPoint` writes proportional / deadband values into the same slot.

### D. Sign evidence is **caller-layer**, not body-layer

- Hard keys (plates / system map): SteerLeft → `+1`, SteerRight → `-1`.
- AI proportional path: `steer = clamp(base * lateral * 2)` with `lateral = R·dir`; golden vector “hard left” → `+1`, “right” → `-1` (`drive-controller-spec.md`).
- Soft band in system map: Soft L → **`-0.5`**, Soft R → **`+0.5`** — polarity **opposite** hard left/right if labels are correct.

### E. Negative evidence (what is *not* in the corpus)

- No producer map for `wobj+0xb4` bits in `0xC7`.
- No per-bit names.
- No runtime/CE observation of gate close under a known “lock.”
- No instruction-level re-measure of body end / immediates in this unit’s completion checklist (function record: open).
- Python model does not execute the retail pointer chain.

---

## 3. Attack results (claim-by-claim)

### Claim 1 — Gate mask is `0xC7` and semantics are “lock”

| Sub-claim | Attack result |
|-----------|----------------|
| Mask value is `199` ≡ `0xC7` | **Not broken.** Decompile is explicit; sibling matches. Residual: no fresh disasm of the immediate this pass. |
| Bits tested are `0x01\|0x02\|0x04\|0x40\|0x80` | **Not broken** as bit expansion of `0xC7`. |
| Semantics = “lock” / “steer lock” / “external override” | **BROKEN as proven semantics.** Zero producers, zero clear paths, zero per-bit evidence in unit artifacts. “Lock” is a story fitted to a suppress-if-any-bit gate. |
| Name `driveAxisLockFlags` / `INPUT_AXIS_LOCK_MASK` / `kSteerLongitudinalLockMask` | **Overconfident.** Shared suppress mask for thr *and* steer is all that is proven. Could be ownership, AI authority, cinematic, network, damage, disabled-subsystem, etc. |

**Alternate interpretations (none ruled out):**

1. **Write-suppress / busy** — subsystem owns axes while updating.
2. **Authority / remote-control** — local input ignored while remote or AI drives.
3. **Lifecycle / teardown** — object present but not accepting player axes.
4. **Multi-flag OR bag** — five unrelated conditions collapsed into one mask; not a single “lock” concept.
5. **Wheel-control lock** (current favorite) — possible, still untyped.

**Severity:** Critical for *naming and port comments* that say “apply lock behavior.” Not a control-flow misread of the mask constant.

---

### Claim 2 — Null `wobj` allows write

| Sub-claim | Attack result |
|-----------|----------------|
| Decompile short-circuit: `iVar1 == 0` → store without flag load | **Not broken.** `||` order is explicit. |
| Null means “unlocked” as a designed retail state | **Not proven.** Could be rare, transitional, or “object missing / not constructed.” Treating null as the normal unlocked case is interpretation. |
| “Null-safe gate” in general | **BROKEN if generalized.** Intermediate loads `*(this+4)` and `*(*(this+4)+4)` are **unconditional**. Null `p0`/`p1` → fault, not “allow write.” Only the **final** `wobj` null is checked. |

**Doc contamination found:** `drive-controller-spec.md` §3 inlines a **different** parenthesization:

```c
// drive-controller-spec (NPC proportional path) — fewer indirections as written:
int wobj = *(int*)(*(int*)(this+4)+4 + this + 0xb0);
// SetSteerInput raw (three loads):
// wobj = *( *(*(this+4)+4) + this + 0xb0 )
```

Either the NPC inline gate was mis-transcribed, or it is not the same chain. The verified setSteerInput note asserts sameness. That is an unresolved cross-doc inconsistency that weakens any “identical everywhere” seal without re-decompile of `0x004fc650`.

---

### Claim 3 — Field `+0x618` is steer input

| Sub-claim | Attack result |
|-----------|----------------|
| Store target of this function is `this+0x618` | **Not broken.** |
| Semantic identity: raw steer axis / command consumed by steering pipeline | **Survives attack.** applyAction stage-1 + feed chain + AI writer + sibling thr at `+0x614` form a coherent map. |
| Name `steerInput` as the only correct field name | **Working name only.** Equally fair: `rawSteerAxis`, `steerCommand`. Not “input” exclusively (AI/network paths write it too). |

**Residual attacks that failed to land:**

- Confusing `+0x618` with `VehicleAction+0x24` (steer *ramp*) — already corrected in prior physics notes; this function does not touch VA.
- Confusing entity `+0x618` with wheels-desc / per-wheel tables that also use `0x618` in other structs — different `this`.

**Severity:** Low for the unit body. High confidence retained.

---

### Claim 4 — No other side effects

| Sub-claim | Attack result |
|-----------|----------------|
| No other stores | **Not broken** (decompile). |
| No callees | **Not broken.** |
| No clamps / ramps / controller push | **Not broken.** |
| Literally zero side effects | **Overstated.** Three unconditional pointer loads can fault; flag byte read when `wobj != 0`. Observable only as crash/AV if chain is bad — still a real behavioral boundary the Python model erases. |

**Not claimed and correctly absent:** mutation of `wobj+0xb4`, writes to `+0x614`/`+0x61c`, PushDriveAxes.

---

### Claim 5 — Sign convention left=`+1` right=`-1` belongs to **this** function

| Sub-claim | Attack result |
|-----------|----------------|
| Function body encodes left/right signs | **FALSIFIED.** Body is a gated bit-pattern store. No sign, no abs, no key bind, no lateral math. |
| Plates / OBJECT_LAYOUTS that attach left→`+1`, right→`-1` to this unit / field as if body-owned | **Overclaim / category error.** Ownership is callers (`DriveControlTick`, `MoveToTarget3DPoint`, …). |
| Axis polarity left positive is sealed globally | **Challenged.** Hard keys + AI golden vectors support left→`+1`. Soft L/R in `input-drive-control.md` assign Soft L → **`-0.5`**, Soft R → **`+0.5`**, and the transitions table pairs SoftR with left polarity and SoftL with right polarity. That is either (a) mislabeled soft actions, (b) wrong float constants, or (c) a real opposite soft band. The system map itself lists bind confirmation as an open check. **You cannot seal a single global L/R sign story while Soft L/R remains inverted relative to hard L/R under the same labels.** |

**What survives:** Several *callers* (not this function) appear to use positive-left for full hard steer and for AI proportional left. That is **not** a property of `0x004f5620`.

---

### Claim 6 — Pure Python model is behaviorally equivalent

File: `docs/reconstruction/experiments/vehicle_entity_set_steer_input.py`.

| Aspect | Equivalent? | Attack notes |
|--------|:-----------:|--------------|
| Gate predicate on resolved lock object | **Yes** | `None` or `(flags & 0xC7)==0` → write |
| Store to a steer float field | **Yes** | logical `steer_input` |
| Sibling longitudinal same gate | **Yes** | same helper |
| Retail pointer chain (3 loads, entity-relative `+0xb0`) | **No** | Collapsed to `entity.lock_object` |
| Intermediate null / bad `p0`/`p1` behavior | **No** | Model cannot AV; retail can |
| Byte-only flag load | **Partial** | Python uses full `int`; OK only if callers pass byte-range flags |
| “Exact-behavior pure model” docstring | **Overclaim** | Gate *predicate* model, not structural/exact retail |

**Verdict on claim 6:** **Not behaviorally equivalent to retail** as a full unit substitute. Acceptable as a **gate-logic test double** only if tests never pretend to cover chain resolution or fault cases.

---

### Claim 7 — Overconfident naming (inventory)

| Name / phrase | Confidence warranted | Attack |
|---------------|----------------------|--------|
| `VehicleEntity_SetSteerInput` | High if Ghidra symbol / plate | Acceptable working name; body does not prove “Input” vs “Axis/Command” |
| `steerInput` @ `+0x618` | High as working field | Prefer “raw steer axis”; multi-writer |
| `driveAxisLockObject` / `wobj` | Probable pointer role only | Type unknown (UF-001) |
| `driveAxisLockFlags` | **Inflated** | “Lock” unproven (UF-002) |
| `kSteerLongitudinalLockMask` / `INPUT_AXIS_LOCK_MASK` | Value confirmed; “Lock” inflated | Rename mentally to `AXIS_WRITE_SUPPRESS_MASK_0xC7` until producers known |
| “wheel-control object” | Probable at best | Repeated as if sealed |
| Plate `WI-MOV-001` text on function | Mixed | Embeds DriveControlTick signs and applyAction ramp into the *setter* plate — confuses unit boundary |
| Physics note status **Verified** | **Inflated vs function record** | Function record: runtime open, bits open, not fully complete; “Verified” implies more than static CF |
| Older `drive-controller-spec` claim deadband SetSteerInput “not subject to this gate” | **Already wrong** | Callee applies gate; verified note corrects this — but wrong text still lives in drive-controller-spec §4 |

---

## 4. Alternate interpretations

### 4.1 What the function *is* (minimal, hard to attack)

```
void thiscall SetSteerAxisRaw(Entity* e, uint32_t bits /* usually f32 pattern */) {
  W* w = resolve_entity_relative_ptr(e); // *(*( *(e+4)+4 ) + e + 0xB0)
  if (w == NULL || ((*(uint8_t*)(w + 0xB4) & 0xC7) == 0))
    *(uint32_t*)(e + 0x618) = bits;
}
```

This minimal reading needs **no** lock story, **no** sign convention, **no** wheel-control type name.

### 4.2 What the function *is not*

- Not a clamp/normalize step.
- Not the ActionMap left/right decoder.
- Not the applyAction ramp.
- Not PushDriveAxes.
- Not a proof that null `wobj` is the common unlocked world state.
- Not a complete inventory of all `+0x618` writers (bypass sites still open).

### 4.3 Competing gate stories

| Story | Fits CF? | Evidence quality |
|-------|----------|------------------|
| Steer/thr lock while maneuver locked | Yes | Narrative only |
| Shared “don’t clobber axes” while another system drives | Yes | Narrative only |
| Damaged / disabled drive subsystem flags | Yes | None in unit pack |
| Accidental / legacy bit bag | Yes | None |

No story above is selected by the binary body alone.

---

## 5. What was confirmed despite skepticism

These resisted falsification from the inspected static corpus:

1. **Control flow shape:** single conditional store; else retain prior `+0x618`.
2. **Mask constant:** decompiler `199` ≡ `0xC7`; byte AND.
3. **Pointer chain shape in *this* function:** three loads, entity-relative final slot (as Ghidra wrote it).
4. **Store offset:** `this+0x618` only intentional write.
5. **No FP math / clamps / callees** in the body.
6. **Sibling gate identity** with `SetLongitudinalInput` (same chain + mask; different store).
7. **`+0x618` as raw steer command into applyAction stage-1** — multi-document consumer agreement.
8. **Function does not own L/R signs** — and that *negative* finding is itself confirmed: signs live in callers.

---

## 6. Critical contradictions found

### C1 — Soft L/R polarity vs hard L/R (caller layer; contaminates “sealed” sign story)

In `input-drive-control.md`:

- SteerLeft → `+1.0`, SteerRight → `-1.0`
- Soft L → `-0.5`, Soft R → `+0.5`
- Transitions explicitly pair SoftR with positive (left-like) and SoftL with negative (right-like)

If Soft L/R labels are correct, **left is not always positive**. If the floats are correct and labels swapped, the **labels** are wrong. Either way, the package cannot honestly claim a sealed, simple “left=+1, right=-1” convention without resolving this. Function-record plates that collapse soft to “`±0.5`” without assignment hide the inconsistency rather than fix it.

**Impact on `aa_004f5620` body CF:** none.  
**Impact on interpretation package / port sign docs:** high.

### C2 — “Verified” / “lock” language vs admitted open work

- Function record: not fully complete; runtime open; bit producers open; wobj type open.
- Physics verified note: Status **Verified**.
- Naming registry / exact C++: “lock” mask names.

That is a **status and semantics contradiction** inside the project corpus, not a second decompile of the body.

### C3 — Deadband gate story (prior)

`drive-controller-spec.md` §4 still says deadband `SetSteerInput` is not subject to the gate. `fn_004f5620_setSteerInput.md` correctly refutes that (callee applies gate). Stale wrong text remains — proof the corpus is not self-consistent on gate coverage.

### C4 — NPC inline gate pointer expression vs setter chain

Parenthesization / indirection count differs in drive-controller-spec vs SetSteerInput raw. Not proven which is wrong without re-decompile of `0x004fc650`, but they cannot both be exact as written.

### Body CF contradictions

**None found** that overturn:

`if (wobj==0 || (flags&0xC7)==0) store_f32(this+0x618)`.

---

## 7. Residual uncertainty

| # | Uncertainty | Blocks sealing? |
|---|-------------|-----------------|
| R1 | Instruction-level immediate / body size not re-measured this review | Mild for mask value; low for CF shape |
| R2 | `wobj` type and field names | Yes for naming / object layouts |
| R3 | Who sets bits in `0xC7` and when | Yes for “lock” semantics and port parity of suppress conditions |
| R4 | Whether null `wobj` is normal | Yes for interpreting null path as “unlocked gameplay” |
| R5 | Soft L/R labels vs float polarity | Yes for global sign convention docs |
| R6 | Full inventory of direct `+0x618` writers / gate bypasses | Yes for system parity |
| R7 | Intermediate chain faults vs pure model | Yes for “exact” Python equivalence claims |
| R8 | Runtime confirmation never done | Yes for any “Verified complete” claim |

---

## 8. Concrete checks performed (not generic approval)

Generic “looks good / LGTM / consistent with prior art” is **explicitly rejected** as a review method here. Checks actually done:

1. **Re-derived control flow** from raw pseudocode alone (null short-circuit, closed gate retains prior).
2. **Converted** decompiler decimal `199` → `0xC7` and expanded bits; checked against annotated + exact C++ + Python constant.
3. **Parsed pointer expression associativity** for SetSteerInput (`p0`, `p1`, `p1+this+0xb0`).
4. **Compared** exact C++ reconstruction line-by-line to annotated CF (chain + gate + single store).
5. **Compared** Python model to retail chain (found structural collapse — not full equivalence).
6. **Cross-read** sibling longitudinal raw for gate parity vs divergent store.
7. **Cross-read** applyAction / steering feed / entity drive-axes docs to attack or support `+0x618` identity.
8. **Cross-read** AI drive-controller golden vectors for independent left/right polarity evidence.
9. **Audited** input-drive-control Soft L/R vs hard L/R for internal contradiction.
10. **Audited** ownership of sign convention (body vs callers vs plates vs OBJECT_LAYOUTS).
11. **Audited** naming registry / C++ mask names for “lock” semantic inflation.
12. **Compared** function-record completion state vs physics note “Verified” status.
13. **Located** stale deadband-bypass claim in drive-controller-spec vs correction in setSteerInput note.
14. **Compared** NPC inline gate expression parenthesization to setter chain.
15. **Confirmed** open gaps UF-001/UF-002 still open and not silently closed by newer prose.

**Not done (and therefore cannot support a stronger verdict):**

- Fresh Ghidra decompile / memory read of immediates.
- Live CE: hold SteerLeft → observe `+0x618`, force `wobj+0xb4` bits → observe suppress.
- Producer xrefs for `+0xb4` flag writes.
- Full DriveControlTick ordered branch dump committed as raw for Soft L/R.

---

## 9. Verdict

### **`needs-more-evidence`**

**Why not `no-critical-contradiction`:**  
The mechanical body CF did not fall, but the *current interpretation package* ships unproven “lock” semantics, over-attaches L/R signs to this function, asserts Python “exact” equivalence it does not have, and carries caller-layer Soft L/R polarity contradiction plus stale gate text in adjacent specs. Accepting the package as-is would launder those claims.

**Why not `critical-contradiction`:**  
No evidence overturns the decompiled gate+store itself (`0xC7` byte mask, null-or-clear allow, store `+0x618`). The successful attacks hit **semantics, naming, equivalence, and sign ownership**, not the core CF equation.

### Acceptance bar for a stronger verdict later

To move toward **`no-critical-contradiction`** on the *full* interpretation (not just CF):

1. Re-decompile or otherwise re-seal `0x004f5620` + NPC inline gate at `0x004fc650` (chain identity).
2. Map at least one real producer/clear of `wobj+0xb4` bits in `0xC7` **or** demote all “lock” names to “axis write suppress mask.”
3. Resolve Soft L/R label/polarity with a committed DriveControlTick raw fragment (not plate prose).
4. Demote Python docstring from “exact-behavior” to “gate predicate model.”
5. Align status words: do not call the unit “Verified complete” while runtime and bit semantics remain open.

### Port guidance under current evidence (adversarial)

- Port the **minimal CF** (claim §4.1).  
- Do **not** invent clamps.  
- Do **not** treat “lock” bit meanings as known.  
- Do **not** implement L/R signs inside this setter.  
- Do **not** trust Soft L/R labels without re-checking constants.  
- Do **not** use the Python model as a full retail substitute for the pointer chain.

---

## 10. Summary table (attack scorecard)

| # | Claim | Result |
|---|-------|--------|
| 1 | Mask `0xC7` | Value holds; **“lock” semantics fail** |
| 2 | Null `wobj` allows write | CF holds; **“null = unlocked design” unproven**; intermediate nulls not safe |
| 3 | `+0x618` = steer | **Holds** (raw steer command) |
| 4 | No other side effects | **No other stores** holds; absolute “no side effects” overstated |
| 5 | Signs belong to this function | **Falsified** |
| 6 | Python ≡ retail | **Gate only; not full equivalence** |
| 7 | Naming | **Several overconfident lock/wheel/Verified labels** |

**Final verdict: `needs-more-evidence`**
)
