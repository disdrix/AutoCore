# Dual A/B report — `aa_005081c0` CVOGHBBase_Start

**Date:** 2026-07-29  
**Scope:** OWN ONLY VA `0x005081c0`. Dual A/B + artifacts. Seal dormant arm + OnStart-only contract.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005081c0` CVOGHBBase_Start | **accept** — **16-byte CF + fDormant@+0x21 + vtbl+4 tail OnStart sealed** |

---

## Sealed facts

1. **ABI:** `void __fastcall CVOGHBBase_Start(CVOGHBBase *this)` — **ECX = this**, **no stack args**, epilogue **`RET`** (not `RET n`). Body **`0x005081c0`–`0x005081cf`**.

2. **`fDormant` is byte `this+0x21`:** gate `cmp [ecx+0x21],0`; clear `mov byte [ecx+0x21],0`. Ctor (`0x00508200`) seeds **`+0x21 = 1`**.

3. **Algorithm:** if dormant ≠ 0 → clear dormant → **tail-call** `*( *this + 4 )` (OnStart); else bare return. **Idempotent** when already armed.

4. **OnStart dispatch:** bytes **`FF 60 04`** = `jmp dword ptr [eax+4]` — **tail-call**, not `call`+`ret`. Decompiler “jumptable” warning is **noise**.

5. **Start ≠ Enqueue / AttachOwner / SetPeriod / stamp lastFire:** body has **no** list ops, period writes, or `+0x14` lastFire store. Callers must schedule separately (e.g. `Skill_StartCastAgainHeartbeat` Enqueue then Start).

6. **TryFire contract (sibling):** period due while still dormant → status **Inactive (2)**; OnHeartBeat only when armed.

7. **Sibling Stop `0x005081d0` (context):** inverse — if not dormant, set `+0x21=1`, tail **`vtbl+0x10`** (OnEnd).

8. **Name:** `CVOGHBBase_Start` — product lifecycle name already on symbol; OnStart English for `vtbl+4` is **INFERRED** from lifecycle (not a string in this unit).

---

## Gaps

1. Exhaustive static audit of 50+ Start call sites for Enqueue / AttachOwner pairing.  
2. Full subclass OnStart side-effect catalog (OKToCastAgain etc. are separate units).  
3. Product/PDB English confirmation for vtbl slots.  
4. Runtime live confirmation; bit-exact / differential — open.

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005081c0_CVOGHBBase_Start.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005081c0_CVOGHBBase_Start.md` |
| Function record | `docs/reconstruction/functions/aa_005081c0_CVOGHBBase_Start.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBBase_Start.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_005081c0_CVOGHBBase_Start.md` |
| Annotated | `docs/reconstruction/raw/aa_005081c0_CVOGHBBase_Start.annotated.md` |
| Scratch | `tmp/a_005081c0.md` |
| This report | `docs/agents/task-dual-ab-005081c0-cvoghbbase-start-report.md` |
| Matrix | `docs/reconstruction/VERIFICATION_MATRIX.md` (row `aa_005081c0`) |

Prior batch note: `docs/agents/task-dual-ab-cvoghb-hbai-report.md` (wave 3 accept, 2026-07-23).

---

## AutoCore impact

- Port Start as **dormant clear + virtual OnStart only** — never fold Enqueue or CD math into this helper.
- After construct, HB remains **Inactive in TryFire** until Start (and usually Enqueue for Tick promote).
- Do not frame-scale or stamp cooldown inside base Start; subclass OnStart / Reschedule / ctor own that.
- Cast-again / regen / patrol paths already call Enqueue then Start — keep that order in server/client ports that mirror client timed-actions.
