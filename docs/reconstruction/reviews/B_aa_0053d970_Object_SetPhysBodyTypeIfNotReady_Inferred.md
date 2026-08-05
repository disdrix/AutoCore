# Review B (skeptical / adversarial): `aa_0053d970` Object_SetPhysBodyTypeIfNotReady_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053d970` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — live Ghidra; independent of Review A narrative polish) |
| **Counterpart** | `reviews/A_aa_0053d970_Object_SetPhysBodyTypeIfNotReady_Inferred.md` |
| **System** | physics / entity shell |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on machine CF + flag→{1,6} + soft-ready gate; **reject** decompiler-only ports, null-this, “always type 6”, and “always calls 5d4440” |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Body is exactly the Ghidra decompile (`FUN_005d4440()` no args) | Trust scaffold | **Falsified** — bytes rewrite stack to **1** or **6** and tail-jmp |
| 2 | No stack argument / `__fastcall` void-only | ABI | **Falsified** — callers `push 0/1`; epilogue **`RET 4`** |
| 3 | `FUN_0053d970(0)` means this=null | Wrong target | **Falsified** — `0` is flag; ECX=entity then reloads phys |
| 4 | Always requests type **6** (“type-6 cleanup” name) | Flag ignored | **Falsified** — flag **0 → type 1**; flag **≠0 → type 6** |
| 5 | Always calls mode switcher | No soft gate | **Falsified** — fully ready (`+0x40≠0` ∧ `+0x08≠0`) → bare `RET 4` |
| 6 | Works without phys shell | Entity-only | **Falsified** — `entity+0x08==0` → no-op |
| 7 | Callee this is the entity | Wrong object | **Falsified** — `mov ecx,[ecx+8]` before jmp; 5d4440 sees **phys** |
| 8 | Uses `CALL` then returns | Stack discipline | **Falsified** — **`JMP 0x005d4440`** tail; early outs `RET 4` |
| 9 | Vehicle-only helper | Scope creep | **Falsified** — creature post-create, spawn, camera, respawn xrefs |
| 10 | Ready byte is unrelated to network soft path | Split semantics | **Fail as overclaim of novelty** — same predicate as `FUN_0053eec0` soft path |
| 11 | Product name sealed / types 1&6 English sealed | PDB | **Fail** — `_Inferred`; enum English open |
| 12 | Runtime / bit-exact sealed | Premature | **Fail** — static machine only |

---

## 2. Decisive dataflow (machine)

```
// __thiscall entity @ ECX; flag @ [esp+4]  (cleaned by RET 4)
phys = *(entity + 0x08)
if (phys == null)
  return;                              // RET 4

notReady = ( *(u8*)(phys + 0x40) == 0 ) || ( *(u32*)(phys + 0x08) == 0 )
if (!notReady)
  return;                              // RET 4 — hard shell untouched

// rewrite flag slot in place for tail-call ABI
if (flag == 0)
  targetType = 1
else
  targetType = 6

// ECX already phys; [esp+4] = targetType; return addr still caller's
jmp FUN_005d4440                       // thiscall (phys, targetType)
```

**Polarity trap:** human label “want type 6” maps to **non-zero flag**, not flag==6. Callers push **boolean-like 0/1**, never the type id itself.

**Name trap:** partition label “Vehicle type-6 cleanup” describes a **frequent caller pattern** (type probe == 6, push 0 → request type **1**), not “this function always sets type 6”.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Null phys no-op | **High** | Crash into 5d4440 / bogus switch |
| Soft-ready dual field gate | **High** | Force type swap on hard shells → physics glitch |
| Flag 0→1 / ≠0→6 | **High** | Invert leave vs enter type-6 |
| Tail ECX=phys | **High** | Entity mistaken for phys → wrong `+0x3c` body |
| `RET 4` / one stack arg | **High** | Stack imbalance on early out |
| 22 static xrefs fan-in | **High** (static) | Missed dynamic only |
| Type 1/6 product meaning | **Low–Probable** | Wrong server/client port labels |
| `+0x40` English (“ready” vs “isType7”) | **Probable CF** | 5d4440 sets `+0x40 = (type==7)`; zero still means not-ready here |
| Runtime golden | **Open** | Residual parity |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| `entity+0x08` phys | Invented? | **No** — first load; matches eec0 / setDrivingInputs |
| `phys+0x40` | Wrong width? | **No** — byte load `8A 41 40` |
| `phys+0x08` | Same as entity+8? | **No** — secondary field on **phys** object |
| Type rewrite 6 then 1 | Flag sense inverted? | **No** — `cmp [esp+4],0` / `jnz keep 6` / `mov 1` |
| JMP target | Wrong rel? | **No** — lands `0x005d4440` |
| setDrivingInputs `(0)` | Null this? | **No** — prior dual + `push 0; mov ecx,esi` |
| Always type 6 from name | Semantic overfit | **Rejected** — flag 0 → type 1 |
| Decompiler completeness | Sufficient for port? | **Rejected** — must use machine |

---

## 5. Surviving contract for AutoCore

```
Object_SetPhysBodyTypeIfNotReady(entity, flag /*0 or 1*/):
  phys = entity.phys                    // +0x08
  if phys == null: return

  if phys.readyByte != 0 and phys.field08 != null:
    return                              // fully ready: no mode change

  targetType = (flag == 0) ? 1 : 6
  Phys_SetBodyType(phys, targetType)    // FUN_005d4440; may no-op if already type
```

**Port tests that matter (behavioral):**

* Null phys → no call into body switcher.
* Fully ready phys → no type change even if flag is 1.
* flag 0 → request type **1**; flag 1 → request type **6**.
* Callee receives **phys**, not entity.
* Vehicle ghost type-6 path uses **flag 0** (leave toward 1) only when type probe == 6 (caller responsibility).
* Stack balanced on all early-outs (`RET 4`).

**Do not:**

* Port from decompiler text alone.
* Treat stack immediate as the body-type id (it is a boolean selector).
* Fold full `FUN_005d4440` AI/body reconstruction into this unit.

---

## 6. Open questions

1. Retail/PDB name for `FUN_0053d970` and `FUN_005d4440`.
2. Design English: type **1** vs **6** vs **7** (walking / soft / turreted paths visible in 5d4440).
3. Whether any caller pushes a flag other than 0/1 (machine treats any ≠0 as type 6).
4. Live confirmation of type-6 ghost soft-shell frequency.
