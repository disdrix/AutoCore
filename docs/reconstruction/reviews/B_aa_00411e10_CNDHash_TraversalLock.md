# Review B (adversarial): `aa_00411e10` CNDHash_TraversalLock

| Field | Value |
|---|---|
| **Stable ID** | `aa_00411e10` |
| **VA** | `0x00411e10` |
| **Canonical name** | `CNDHash_TraversalLock` |
| **Review date** | `2026-08-05` (OWN-ONLY dual A/B — MEGA-113) |
| **Reviewer role** | Adversarial / claim-falsification (Path B) |
| **Counterpart** | `reviews/A_aa_00411e10_CNDHash_TraversalLock.md` |
| **System** | interaction-activation / shared CNDHash |
| **Live tools** | Same Ghidra HTTP set as Path A (independent re-read of decompile, bytes, xrefs, call sites) |
| **Partition** | MEGA-113 exclusive VA `0x00411e10` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Adversarial claims tested

| # | Attack claim | Result | Evidence |
|---|---|---|---|
| B1 | Product identity is `VOG_DEBUG_STOP` / `Named_VOG_DEBUG_STOP_00411e10` | **FALSIFIED** | That string is only the second log on the error path; primary string is `HashError:TraversalLock…`; body is a 1-byte flag set |
| B2 | MSVC `__thiscall` (ECX=this) | **FALSIFIED** | No `mov esi,ecx`; body uses ESI only; callers load ESI from object hash fields then bare `CALL` |
| B3 | `RET 4` / stack arg hash* | **FALSIFIED** | Epilogue is bare `C3`; `ADD ESP,0x10` is only for the two cdecl logs |
| B4 | Early-return on double-lock (like `List_TraversalLock`) | **FALSIFIED** | `JZ` skips logs only; `MOV [ESI+0x1d],1` is fallthrough after both paths |
| B5 | Enters Win32 CS / mutex | **FALSIFIED** | No `EnterCriticalSection`; only CMP/JZ/PUSH/CALL/MOV/RET |
| B6 | Same as `List_TraversalLock` (`0x004294f0`) | **FALSIFIED** | List uses ECX, flag `+0x28`, CS `+4`, ~4 KiB stack dump; this is ESI, flag `+0x1d`, 38 B leaf |
| B7 | Throws / noreturn on re-lock | **FALSIFIED** | Soft log only; always returns after set |
| B8 | Walks buckets / freelist / inserts | **FALSIFIED** | No table/freelist refs; single flag store |
| B9 | `unaff_ESI` is decompiler garbage / undefined | **FALSIFIED** | Call sites systematically `mov esi, [obj+hashOff]` immediately before call; ESI ABI is intentional |
| B10 | Unlock is this same VA | **FALSIFIED** | Body only writes `1`; unlock is inline `mov byte [hash+0x1d],0` in callers (e.g. `0x0091be46`) |
| B11 | Only used by interact icons | **FALSIFIED** | 16 xrefs: UI reload, object `+0x4c0` walkers, char mission hashes `+0x538`/`+0x6f0`, etc. |
| B12 | SkillCNDHash-only thiscall twin | **FALSIFIED** | ABI is ESI custom (host/shared CNDHash style), not skill thiscall |

---

## 2. Residual risks (not falsified — gaps)

| Gap | Why open |
|---|---|
| Product C++ class name | No RTTI on this leaf; stamp family not read from this VA |
| Which hash stamp(s) | Callers pass multiple embeddings (`+0xe8f4`, `+0x4c0`, `+0x538`, `+0x6f0`, `+0x53c`) — shared leaf across families |
| Intentional re-lock API vs debug residual | Soft-continue may be intentional same-thread re-enter; no runtime proof |
| Orphan xref parent names | 5 sites lack Ghidra function heads; bytes still show same ESI preload pattern |
| Runtime / bit-exact / differential | No Launcher (forbidden) |

---

## 3. Cross-check vs Path A

| Item | A | B |
|---|---|---|
| Body range 38 B | agree | agree |
| ESI ABI / bare ret | agree | agree |
| Always set `+0x1d=1` | agree | agree |
| Name `CNDHash_TraversalLock` | agree | agree (string-sealed role) |
| Reject Named_VOG_DEBUG_STOP | agree | agree |
| Verdict | accept-with-gaps | **accept-with-gaps** |

No Path A claim required reversal. Adversarial passes strengthen ABI and odd-behavior seals.

---

## 4. Verdict

**accept-with-gaps** — machine CF/ABI/role sealed; product class English + runtime remain open. Terminal **false**.
