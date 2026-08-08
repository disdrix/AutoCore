# Systemic Risks — AUDIT-2026-08-05-01

Cross-cutting failure modes that can invalidate unsampled work or mislead agents.

---

## SR-01 — Status vocabulary collapses distinct qualities

| Field | Value |
|-------|-------|
| Risk | `full` / `terminal_full_coverage` / “sealed” / dual “accept-with-gaps” are read as completion |
| Mechanism | Industrial batch wrote three-rep scaffolds and stamped inventory `full`; dual waves stamp CHANGE_LOG “sealed” for static duals |
| Affected scope | ~17042 inventory full; ~15k Partial scaffold records; dual corpus marketing |
| Detection | Function-record completion phrase scan; dual vs reviewed mismatch |
| Containment | Rename/annotate statuses; ban “complete” without runtime or explicit static-only banner |
| Related findings | F-001, F-002, F-008 |

---

## SR-02 — Dual-count throughput displaces vertical user-facing reconstruction

| Field | Value |
|-------|-------|
| Risk | Agents optimize for dual A∩B unique count |
| Mechanism | Residual waves select undualed callees of dualed parents → STL/map helpers score high as “HP callee” |
| Affected scope | R10–R13 style waves; ~44% dual names `*_Inferred`; 67/80 recent duals non-user-facing |
| Symptom | Dual 10%→11% while WQ-001..008 still partial, runtime N |
| Containment | Freeze residual dual waves; require user-facing vertical score for dual eligibility |
| Related | F-004, F-010 |

---

## SR-03 — Progress files are eventually-consistent at best, wrong at worst

| Field | Value |
|-------|-------|
| Risk | `progress.json`, RESUME, ACTIVE_WORK, CHANGE_LOG disagree with disk |
| Mechanism | Parallel OWN agents land duals faster than parent merge; seals use start-of-wave counts |
| Affected scope | All dual metrics; any consumer of progress.json |
| Detection | Failing `test_progress_dual_matches_filesystem_A_and_B` |
| Containment | Single writer for progress.json; count duals only at merge; CI gate |
| Related | F-003, F-010, F-020 |

---

## SR-04 — “Independent dual review” is often same-wave OWN-ONLY

| Field | Value |
|-------|-------|
| Risk | A and B written by same partition owner → correlated blind spots |
| Mechanism | Wave maps assign one agent both Path A and Path B artifacts |
| Mitigant | Text independence real; skeptical templates falsify claims (StdTree sample) |
| Residual risk | Shared wrong gate/object story across A/B still possible |
| Containment | Require separate agent IDs for A vs B on priority ≥90 units |
| Related | F-016 |

---

## SR-05 — Static dual treated as Confirmed behavior

| Field | Value |
|-------|-------|
| Risk | Matrix Ind.rev=Y + dual seal → agents raise confidence to Confirmed |
| Mechanism | No runtime experiments; model unit tests pass on reconstructed Python/C++ gate clones |
| Affected | Entire dualed set (~2.7k) |
| Containment | Hard rule: Runtime=N ⇒ Overall ≠ complete; Confirmed only with traces |
| Related | F-005, F-008 |

---

## SR-06 — Docs ↔ Ghidra divergence

| Field | Value |
|-------|-------|
| Risk | Clean/docs correct; Ghidra types/names wrong → next decompile re-poisons work |
| Mechanism | Reconstruction writes filesystem only; rarely applies Ghidra type commits |
| Affected | Even High units (SetSteerInput signature) |
| Containment | Type-commit step for dual-accepted HP units |
| Related | F-006 |

---

## SR-07 — Industrial scaffold mass is un-auditable at dual depth

| Field | Value |
|-------|-------|
| Risk | 17k full units cannot receive dual reviews at current rate without years |
| Mechanism | Terminal accounting goal met by scaffold + trivial-batch |
| Impact | Any claim of “program reconstructed” is false |
| Containment | Split goals: (1) inventory accounting (2) dual depth (3) runtime-confirmed verticals |
| Related | F-001, F-009 |

---

## SR-08 — Encoding and matrix structural rot

| Field | Value |
|-------|-------|
| Risk | Mojibake and truncated matrix rows hide or corrupt verification claims |
| Mechanism | Parallel UTF-8/cp1252 edits; manual row inserts mid-table |
| Containment | Encoding normalize pass; matrix schema validator |
| Related | F-007, F-012 |

---

## SR-09 — System tags and naming registry not authoritative

| Field | Value |
|-------|-------|
| Risk | Inventory system=None for nearly all; duals invent `*_Inferred` outside registry |
| Impact | Cannot enforce priority order or name consistency programmatically |
| Containment | Backfill system tags for dualed+HP; registry gate for renames |
| Related | F-013, F-015 |

---

## SR-10 — Positive control: methodology works when focused

| Field | Value |
|-------|-------|
| Observation | SetSteerInput / HasCompletedMission / InventoryGrab static claims matched live bytes/decomp |
| Implication | Failure is **process allocation and metrics**, not total inability to reconstruct |
| Use | Corrective plan should restore focus, not scrap dual method |

---

## Risk heat map

| Risk | Likelihood | Impact | Priority |
|------|------------|--------|----------|
| SR-01 Status inflation | Certain | Critical | P0 |
| SR-02 Dual throughput drift | High | Major | P0 |
| SR-03 Metric desync | Certain | Major | P0 |
| SR-05 Static as Confirmed | High | Major | P0 |
| SR-06 Ghidra lag | High | Major | P1 |
| SR-04 Dual independence | Medium | Moderate | P1 |
| SR-07 Scaffold scale | Certain | Major (strategic) | P1 |
| SR-08 Doc rot | Medium | Moderate | P2 |
| SR-09 Tags/registry | High | Moderate | P2 |

---

## Estimated unsampled contamination

| Cluster | Est. size | Contamination mode |
|---------|----------:|--------------------|
| Industrial Partial scaffold `full` | ~15,000–16,000 | Not dualed; not semantic |
| Dualed but inventory still `full` | ~2,500+ | Dual quality variable; many Inferred/STL |
| Dualed inventory `reviewed` | 121 | Higher quality; still runtime-open |
| Trivial-batch | 8508 | OK if kept trivial |
| HP managers dualed | ~100–200 | Best quality; static-only |
