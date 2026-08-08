# Current Audit — Client Verified Decompilation

| Field | Value |
|-------|-------|
| Audit ID | `AUDIT-2026-08-05-01` |
| Date | 2026-08-05 |
| Auditor | Independent session (not prior reconstruction agent chain) |
| Target binary | `autoassault.exe` (image base `0x400000`) |
| Ghidra program | Live MCP `autoassault.exe` |
| Scope | Process compliance + risk-weighted sample verification |
| Primary goal | Verify whether reconstruction work matches project requirements |
| **Rating** | **PARTIAL FAILURE** |

---

## Executive summary

The project has **real high-quality work on a thin high-priority core**, and **large-scale inventory accounting that overstates reconstruction depth**.

What holds up under live Ghidra verification:

- Dual-reviewed high-priority units (steer/longitudinal/handbrake setters, mission completion predicate, inventory grab pack path) preserve control flow, constants, and side-effect order against decompiler + `read_memory`.
- Dual A/B reviews are textually independent (not copy-paste) and frequently document residual gaps as `accept-with-gaps`.
- Explicit honesty language exists in `COVERAGE_LEDGER.md` that dual depth ≠ terminal accounting.

What fails the project requirements:

1. **Progress inflation via status vocabulary.** Inventory `full` (17042) and `terminal_full_coverage=true` mostly mean *industrial three-rep scaffold present*, not *behaviorally reconstructed and verified*. **~81%** of function records are still labeled **Partial scaffold**.
2. **Verification depth is shallow for the bulk corpus.** Dual A∩B ≈ **2700+** (~10–11% of 25671) while inventory `reviewed` is only **121**. Runtime / differential verification is **N for essentially all units**.
3. **Priority drift.** Recent residual dual waves (R10–R13) predominantly dual leaf `FUN_*` / STL / `*_Inferred` callees rather than unfinished user-facing verticals still marked `partial` on the work queue.
4. **State integrity defects.** `progress.json` dual count lagged filesystem (test failure `2686 != 2705+`); matrix has truncated rows; encoding corruption in several ledgers; ACTIVE_WORK “R13 in flight” while duals partially land without parent merge honesty.
5. **Ghidra type fidelity lags docs.** Even sealed units (e.g. `VehicleEntity_SetSteerInput`) still show weak Ghidra signatures (`undefined` return, `int` this, untyped float arg).

**Not** a pure systemic failure: the dual-review methodology for important units is capable of producing evidence-backed reconstructions. The failure mode is **volume accounting and residual dual expansion outrunning verified user-facing behavior**.

---

## Method

### Sampling (risk-weighted + random)

| Stratum | n | Method |
|---------|--:|--------|
| High-priority externally observable | 12 | Work-queue / system-map managers (input, missions, inventory, skills, interaction) |
| Dual-reviewed / “confirmed-static” units | 20 | Inventory `reviewed` + dual A/B present |
| Large / complex | 3 | DriveControlTick, CompleteObjective, industrial XML parse `FUN_0048dde0` |
| Recent residual duals | 80 dual A files | mtime-sorted review corpus |
| Random inventory `full` | 25 + 500 quality probe | seed 42 / seed 1 |
| Trivial-batch legitimacy | 20 | random Unwind@/Catch@ |
| Types / layouts | 4 docs | OBJECT_LAYOUTS, TYPE_REGISTRY, Vehicle drive axes, InventoryGrid |
| Project state integrity | full | progress/ledger/queue/resume/active/matrix/tests |

**Total functions inspected in depth (live Ghidra decompile and/or bytes):** 14 primary + multiple supporting callees.  
**Total artifacts sampled (records/reviews/cleans):** >100 unique VAs.  
**Independent audit agents launched:** assembly/CF adversarial + project-state integrity (background; findings merged with parent live checks).

### Evidence tools used

- Ghidra MCP: `batch_decompile`, `decompile_function`, `analyze_function_complete`, `read_memory`
- Filesystem: `functions/`, `raw/`, `reconstructed-exact/`, `reviews/`, `coverage/inventory.jsonl`, `progress.json`
- Tests: `python -m unittest discover -s docs/reconstruction/experiments -v` (111 tests; **2 failures**)

### What was deliberately not trusted

Prior agent completion claims, confidence tables, dual verdicts, `terminal_full_coverage`, `full_coverage`, and CHANGE_LOG seal language — all re-checked against binary/artifacts.

---

## Quantitative results

| Metric | Result | Notes |
|--------|--------|-------|
| Live inventory size | **25671** | Matches claimed list_functions universe |
| Inventory status | full **17042** · trivial-batch **8508** · reviewed **121** | none/raw/partial = 0 |
| Dual A∩B on disk (audit window) | **~2709–2724** and rising (R13) | progress.json claimed **2686** → **stale** |
| Inventory `reviewed` | **121** | **≪ dual pairs** — status not updated for duals |
| Function records with “Partial scaffold” head | **15299 / 18800 ≈ 81.4%** | Dominant “completed” quality |
| Random full artifact triad present | **25/25** | raw + function record + clean exist |
| Random full with dual A/B | **4/25 (16%)** | Most “full” are undualed |
| Sampled reviewed with dual A/B | **20/20** | Inventory reviewed subset is dualed |
| High-pri sample with dual A/B | **12/12** | |
| Dual A containing `Inferred` | **1202 / ~2752 ≈ 44%** | Naming uncertainty dense in dual corpus |
| Recent dual name pattern (80) | STL/FUN/Inferred **67** · user-facing-ish **12** | Priority drift |
| R13 partition dual complete (mid-audit) | **23/40** | ACTIVE_WORK “in flight” partially accurate |
| Assembly-verified control flow (deep sample of 8 HP units) | **8/8 ≈ 100%** of *that* stratum | Not extrapolate to all full |
| Evidence-supported signatures (same 8) | **~7/8 High static; 1 EDI/register ABI residual** | InventoryGrab EDI documented |
| Defensible names (same 8) | **~6/8 High; 2 role-High / product-open** | |
| Side-effect order preserved (same 8) | **8/8** | No silent branch removal found |
| Adequate uncertainty docs (HP dualed) | **~90%** | accept-with-gaps common |
| Adequate uncertainty docs (industrial full sample 30) | **29/30 mention Tentative/Probable/Unknown** | But shallow |
| Claimed runtime verification reproducible | **0%** | RUNTIME_EXPERIMENTS empty; matrix Runtime = N |
| Unit tests for reconstructed gate model | **mostly pass** | Structural + pure model; not live binary |
| Test failures at audit | **2** | dual count desync; one clean `undefined4` policy |
| Short / broken verification matrix rows | **≥7** | Truncated columns |
| Critical findings | **3** | See AUDIT_FINDINGS |
| Major findings | **9** | includes F-027 mode-gate attach `this` |
| Moderate findings | **9** | |
| Minor findings | **6** | |
| Estimated affected unsampled work | **~15k–17k “full” scaffolds** unreviewed; **~2.5k duals** not inventory-reviewed | Clustered by industrial batch method |

### Deep sample outcome rates (n=8 HP + 1 industrial complex)

| Check | HP dualed (n=8) | Industrial scaffold (n=1 deep + 12 clean heads) |
|-------|-----------------|-----------------------------------------------|
| Correct boundary | 100% | Plausible / unproven |
| Assembly/decomp CF match | 100% | Clean tracks decomp CF (SEH preserved in sample) |
| Evidence-supported signature | 87% High | Tentative / decompiler-derived |
| Defensible product name | 75% High | FUN_* retained |
| Side-effect order | 100% | Preserved at decomp fidelity |
| Uncertainty documented | 100% | Scaffold boilerplate |
| Runtime evidence | 0% | 0% |

---

## Rating justification

### Why not PASS / PASS WITH CORRECTIVE ACTIONS only

- A **meaningful majority** of work marked inventory-complete is scaffold-only.
- Dual expansion has become a **throughput metric** that increasingly duals STL leaves while user-facing WQ items remain `partial` and runtime-open.
- Progress files and tests **disagree with the filesystem**, so status cannot be trusted without re-measurement.

### Why not SYSTEMIC FAILURE

- High-priority dual methodology produces **byte-checkable** results (e.g. SetSteerInput imm `0xC7` / store `+0x618` match `read_memory`).
- Project docs **do** state dual depth incomplete and runtime open (when read carefully).
- Dual A/B are not rubber-stamp clones (Jaccard ~0.31 on recent pairs).
- Object layouts keep unresolved offsets explicit.

### Final rating

# **PARTIAL FAILURE**

A meaningful portion of “completed” work is **insufficiently verified** relative to how progress is presented, and residual process energy is **misaligned** with the stated priority model. The high-priority dualed core is salvageable and largely sound; the bulk industrial corpus must not be treated as reconstructed behavior.

---

## Immediate containment (executed / required)

1. **Stop treating `full` / `terminal_full_coverage` as dual-verified or behavior-complete.**
2. **Do not resume large residual dual waves on STL leaves** until corrective plan items CAP-001–CAP-004 land.
3. **Preserve this audit** under `docs/reconstruction/audits/`.
4. **Queue corrective work** in `WORK_QUEUE.md` (WQ-AUDIT-*).
5. **Refresh dual count honesty** and mark inventory dual mismatch as open defect.

---

## Related audit files

| File | Role |
|------|------|
| `AUDIT_FINDINGS.md` | Finding catalog with severity |
| `SAMPLED_ITEMS.md` | Per-item verification records |
| `SYSTEMIC_RISKS.md` | Cross-cutting failure modes |
| `CORRECTIVE_ACTION_PLAN.md` | Prioritized remediation |

---

## Sign-off

| Item | Value |
|------|-------|
| Rating | **PARTIAL FAILURE** |
| Highest-priority next action | CAP-001: Progress vocabulary + metric honesty repair |
| Large-scale decompilation | **Suspended** until critical systemic risks contained |
| Evidence destruction risk | None — audit preserves prior artifacts as-is |
