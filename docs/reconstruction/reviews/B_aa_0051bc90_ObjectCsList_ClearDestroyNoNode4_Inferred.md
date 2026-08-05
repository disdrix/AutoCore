# Review B (skeptical / adversarial): `aa_0051bc90` ObjectCsList_ClearDestroyNoNode4_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051bc90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-S) |
| **Counterpart** | `reviews/A_aa_0051bc90_ObjectCsList_ClearDestroyNoNode4_Inferred.md` |
| **Scratch** | `tmp/a_0051bc90.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Same body as `0051b8a0` (merge twins) | **Falsified** — twin writes `node+4=0`; this unit does not; different callers |
| 2 | This is list complete dtor | **Falsified** — callers still `DeleteCriticalSection` / free after; this only drains |
| 3 | Frees list object | **Falsified** — no `operator_delete` here |
| 4 | stdcall / free function | **Falsified** — `MOV ESI,ECX`; thiscall/fastcall |
| 5 | Next pointer at `node+0x10` | **Falsified** — machine uses `node[2]` / `+8` |
| 6 | Throw is access-violation SEH only | **Falsified** — explicit `_CxxThrowException` with `0x80070005` |
| 7 | Product name is retail | **Overstated** — structural `_Inferred` twin of W30-F |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Drain under CS | **High** | Use-after-free / lock bugs |
| No `node+4` clear | **High** | Wrong merge with 0051b8a0 port |
| Flag throw | **High** | Silent wrong path |
| Dtor-only callers | **High** | Wrong call site ownership |
| Product English | **Medium** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
PUSH EBP; MOV EBP,ESP; SEH; chkstk 0x1004
MOV ESI,ECX; LEA EDI,[ESI+4]; EnterCS(EDI)
CMP [ESI+0x28],0; MOV EAX,[ESI+0x1C]
JZ drain; LeaveCS; throw 0x80070005
drain: MOV EDX,[EAX+8]; MOV [ESI+0x1C],EDX; CALL [vtbl](1); loop
MOV [ESI+0x24/20/1C],0; ADD ESI,4; LeaveCS; C3
```

Live 2026-07-29 ≡ raw 2026-07-23 CF. Callers: list dtors only (not SharedBase).

---

## 4. Surviving contract for AutoCore

```
// List method — dtor path drain (no node+4 clear):
ObjectCsList_ClearDestroyNoNode4_Inferred(list);
// Keep distinct from ObjectCsList_ClearDestroy_Inferred (0051b8a0)
// and from List_ClearDestroy (0040dc40 next@+0x10).
// Do not free list/CS here; callers DeleteCS / operator_delete.
```

---

## 5. Verdict

Adversarial pass **confirms** A: twin split, CF/ABI, CS/flag/next sealed; product English open → **accept-with-gaps**.
