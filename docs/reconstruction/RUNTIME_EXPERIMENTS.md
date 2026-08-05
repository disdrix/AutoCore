# Runtime Experiments

No live client runtime experiments were executed in this goal run.

| Experiment ID | Status | Reason |
|---------------|--------|--------|
| — | none | Runtime requires retail client instrumentation and/or Launcher; Launcher start requires explicit user approval (AGENTS.md). Verification matrix marks Runtime = N for active units. |

## Candidate future experiments (not run)

| ID | Question | Preconditions | Steps (outline) |
|----|----------|---------------|-----------------|
| RT-STEER-001 | Does SetSteerInput skip writes when lock flags & 0xC7 nonzero? | Live client + CE/Ghidra debug | Break `0x004f5620`; force wobj+0xb4 bits; hold steer; observe +0x618 |
| RT-STEER-002 | Confirm action-map DAT flags for left/right/soft | Live client | Watch `DAT_00d1bc8e` / `d1bcc2` / soft flags while binding keys |

Results must be logged here with addresses, observations, and confidence impact when run.
