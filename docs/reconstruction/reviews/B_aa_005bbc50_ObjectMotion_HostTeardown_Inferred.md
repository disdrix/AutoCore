# Review B (skeptical / adversarial): `ObjectMotion_HostTeardown_Inferred` / `FUN_005bbc50` @ `0x005bbc50`

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bbc50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W30-S) |
| **Counterpart** | `reviews/A_aa_005bbc50_ObjectMotion_HostTeardown_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is missileExplosion logic | **Falsified** — no string; scaffold chain only; body is buffer/list teardown |
| 2 | ECX at slot release is the host | **Falsified** — `mov ecx, 0x00B036C0` before `FUN_005be2b0` |
| 3 | Function `operator_delete`s each slot payload | **Falsified** — freelist push via W28-I helper; list tick/other owns payload lifetime |
| 4 | Ghidra body end is true function end | **Falsified** — `c3` after SEH tail beyond `005bbd96` |
| 5 | Decompiler single `operator_delete` empties full list | **Incomplete** — bytes show `jnz` free loop; noreturn artifact |
| 6 | `FUN_005be310` is this unit | **Out of scope** — W30-R owns wrapper |
| 7 | Product name retail | **Overstated** — `_Inferred` |
| 8 | Runtime verified | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Slot freelist ECX global | **High** | corrupt wrong pool |
| Host is large object with `+0xa24` list | **High** | wrong type port |
| Buffers SSO-or-heap | **High** | double-free inline storage |
| Full list node free | **Medium-High** | leak list wrappers |
| Product English | **Medium** | docs only |
| Runtime | **Open** | matrix |

---

## 3. Cross-check against raw + bytes

```
SEH
clear/free primary (+0x308 / +0x14)
if +0x7fc: clear/free secondary (+0x6ec / +0x3f8)
for each list node at +0xa24:
  SlotReleaseToFreelist(DAT_00b036c0, node[2])
reset list; free nodes; free sentinel; host+0xa24=0
SEH out; ret
```

Entry SEH `6a ff 68 …`. Slot site `B9 C0 36 B0 00`. Exit `… 83 c4 10 c3 cc`.

---

## 4. Surviving contract for AutoCore

```
// ECX = host with motion slot list at +0xa24
// MUST freelist-release payloads via global DAT_00b036c0 — not delete slots here
// MUST free heap buffers only when pointer ≠ inline storage
// MUST NOT treat Ghidra noreturn on operator_delete as true control end
// FUN_005be310 owns optional freelist push of the host after this returns
```

Do not invent missile/explosion behavior. Do not merge with `ObjectMotion_SlotListTick`.

---

## 5. Verdict

Adversarial pass **confirms** A on role, freelist global, and buffer free shape; keeps gaps on buffer typing and list-free decompiler distortion → **accept-with-gaps**.
