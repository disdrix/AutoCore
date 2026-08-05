# Review A (reconstruction fidelity): `aa_009440e0` VOGClient_CompletelyDestroyObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_009440e0` |
| **VA** | `0x009440e0` |
| **Canonical name** | `VOGClient_CompletelyDestroyObject` |
| **Prior names** | `FUN_009440e0`, `Named_VOGClient_009440e0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_009440e0_VOGClient_CompletelyDestroyObject.md` |
| **System** | `inventory-transfer` / client object lifecycle |
| **Dual status** | **Present** (A + B) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Client-side complete destruction of a world/UI object** (`VOGClient.cpp` line **0x1366**), with hard safety rails and type-specific unbind paths.

String-sealed identity:

```
!!!!CompletelyDestroyObject COID:%I64d global:%d CBID:%d Unique:%s force:%d death:%d
Attempting to delete your character... bad bad
Object %I64d (%d) isn't a valid object to delete. Most likely a map synch issue.
C:\vog\1_code\vog_14_117_branch\appClient\VOGClient.cpp
```

### High-level stages

1. **Refuse deleting local character** — if `obj == client.playerObject` → assert log + return.
2. **Log** CompletelyDestroyObject with COID (`obj+0x160/+0x164` as `obj[0x58]/[0x59]`), global flag, CBID from clonebase `+0x34`, unique name, force, death.
3. **Map dirty / selection clear** — optional flags; clear selected object if destroying selection.
4. **Validate** via object vfunc `+0x1cc` (map membership); warn if null.
5. **Prep:** `FUN_0093ffb0`; death/vfunc `+0x50(death)`; clear interact FX; client vtable remove/unlink.
6. **Class switch** on `clonebase+0x38`:
   - **0x0E** (character-related): nested vehicle/passenger unbind, possible UI close, recursive destroy of dependents.
   - **0x14 / 0x12**: attachment/parent unbind (hardpoint occupant style).
   - **0x16**: special UI path `FUN_007fef20(0xb,…)`.
   - **else**: detach from parent vehicle if foreign; inventory unstamp path `FUN_00571b60` / vfunc `+0x2a8`.
7. **Tail:** net/mask updates; optional `FUN_004962b0` gfx host; `FUN_00933370` finalize.

**Calling convention (recovered):**

| Slot | Role | Evidence |
|------|------|----------|
| `EDI` | `VOGClient* this` | entry `mov eax,[edi+0xE98]`; callers `mov edi,esi` |
| stack0 | `Object* obj` | `mov esi,[esp+…]`; callers push object |
| stack1 | `force` (low byte used) | log `force:%d`; equip pushes `1` |
| stack2 | `death` | log; vfunc `+0x50(param_3)` |
| stack3/4 | often `0xFFFFFFFF` sentinels | unequip/equip full calls |

Decompiler under-declares arity (shows 3 params + unaffs); multi-arg call sites push up to **5** stack values.

---

## 2. Inspected artifacts

| Artifact | Path / evidence |
|---|---|
| Raw | `docs/reconstruction/raw/aa_009440e0_FUN_009440e0.md` |
| Annotated | `docs/reconstruction/raw/aa_009440e0_FUN_009440e0.annotated.md` |
| Clean (scaffold) | `docs/reconstruction/reconstructed-exact/FUN_009440e0.cpp` |
| Function record | `docs/reconstruction/functions/aa_009440e0_FUN_009440e0.md` |
| Live re-decompile | Ghidra MCP ≡ raw CF / strings |
| Bytes | entry `83 EC 08 8B 87 98 0E 00 00` — `client+0xE98` local player |
| Callers | Equip (null vehicle / previous-out); Unequip; Drop response; DestroyObject recv; internal `0x0094494d` |

**Not performed:** full human-refine of every class branch, `disassemble_bytes`, Launcher, bit-exact.

---

## 3. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Local player guard (`client+0xE98` → object*) | **Yes** |
| CompletelyDestroyObject log + `vog_LogMessage` VOGClient.cpp:0x1366 | **Yes** |
| Selection clear `client+0xE08` (`[0x382]`) when matches obj | **Yes** |
| Validate vfunc `+0x1cc` | **Yes** |
| Clear interact FX `CVOGObject_SetInteractSpecialFX(obj,0)` | **Yes** |
| Class `clonebase+0x38` switch 0xE / 0x14 / 0x12 / 0x16 / default | **Yes** |
| Default: parent vehicle detach + inventory path | **Yes** |
| Tail gfx host `+0xE04/+0xE898` → `FUN_004962b0` | **Yes** |

### 3.1 Object offsets used

| Offset | Role | Evidence |
|--------|------|----------|
| obj `+0xA8` (`[0x2a]`) | clonebase* | CBID `+0x34`, class `+0x38`, unique `+0x40` |
| obj `+0x160/+0x164` (`[0x58]/[0x59]`) | COID lo/hi | log + messages |
| obj `+0x168` (`[0x5a]`) | global flag (byte) | log |
| obj `+0xAC` (`[0x2b]`) | parent / vehicle link | default detach |
| client `+0xE98` (`[0x3a6]`) | local player root | character guard |
| client `+0xE08` (`[0x382]`) | selected object | clear on destroy |

---

## 4. Naming

| Claim | Confidence |
|---|---|
| Product `CompletelyDestroyObject` on VOGClient | **High / Sealed** (format string + source path) |
| Canonical `VOGClient_CompletelyDestroyObject` | **High** |
| Full arity / all class branches bit-exact | **Open** (scaffold clean) |

---

## 5. Confidence by dimension

| Dimension | Level |
|---|---|
| Identity / purpose | **High / Sealed** |
| Local-character refuse | **High / Sealed** |
| Log field map | **High** |
| Class-switch skeleton | **High** |
| Nested branch completeness | **Probable** (large; not line-audited 100%) |
| Stack arity exact | **Probable** (call sites vary 2–5 pushes) |
| Runtime / diff | **Open** |
| Overall | **accept-with-gaps** |

## 6. Gaps

- Human-refined clean for all class arms
- Exact meaning of force/death/sentinel stack args
- Full net-mask / first-time-tip side paths
- Runtime destroy scenarios (equip previous-out, S2C destroy, drop)
