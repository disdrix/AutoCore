# Review B (skeptical / adversarial): `aa_0056a260` Weapon_SetFireFlagPair_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056a260` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0056a260_Weapon_SetFireFlagPair_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` / `force_decompile` + `read_memory` body + call-site bytes. No `disassemble_bytes`. Own VA `0x0056a260` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `this` is vehicle entity | Call sites `mov ecx, [table+i]` from `vehicle+0x260` | **Falsified** — **weapon/hardpoint slot object** |
| 2 | Offset `+0xC7` is the **drive suppress mask** `0xC7` | Mask is imm on lockobj `+0xb4`; here displacement is field offset | **Falsified conflation** — different families |
| 3 | Both bytes always rewritten | Conditional `jz` skips `+0xC8` store when equal | **Falsified** — **+0xC8 change-gated**; **+0xC7 always** |
| 4 | Decompiler order is instruction order | Bytes: CMP +0xC8, then MOV +0xC7, then conditional MOV +0xC8 | **Partial** — decomp reorders stores; **CF equivalent** |
| 5 | Two stack args / stdcall | Epilogue **`C2 04 00`** | **Falsified** — one stack dword cleaned |
| 6 | Body is pure always-store like SetHandbrake | Handbrake is single store; this has cmp/jz | **Falsified as single-store** — dual with gate on twin |
| 7 | Only airStab “stabilizer” API | Fire-all / start-fire / DriveControlTick / net unpack share `+0x260` table | **Falsified exclusivity** — **hardpoint weapons**; airstab clears fire flags |
| 8 | `FUN_0056d520` must call this | Start-fire **inlines** +0xC7/+0xC8=1 (+ sets +0xC9) | **Falsified as sole writer** — **inline twin** exists |
| 9 | Three-rep diverges | force_decompile ≡ raw ≡ first live decompile; bytes match | **Falsified** |
| 10 | Void display means wrong ABI | RET 4 + stack load of value sealed | **Falsified concern** — void return is correct; Ghidra `undefined FUN…(void)` signature display is stale |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall weapon + u8 value + RET 4 | **High** | Stack smash / wrong ECX |
| Always +0xC7, change-gated +0xC8 | **High** | Miss dirty/edge semantics |
| Leaf / no callees | **High** | Invented side effects |
| `this` from vehicle+0x260 hardpoints | **High** | Wrong object layout port |
| Same pair as start-fire inline | **High** | Divergent fire-state model |
| Product English “fire request vs latched” | **Medium** | Doc-only; both equal after call |
| Non-0/1 value domain | **Medium** | Unknown exotic writers |
| Full reader inventory | **Open** | Incomplete combat port |
| Runtime / bit-exact | **Open** | Shipping combat fidelity |

---

## 3. Cross-check against raw + bytes

```
raw / force_decompile:
  *(char*)(this + 199) = value;           // +0xC7
  if (*(char*)(this + 200) != value)      // +0xC8
    *(char*)(this + 200) = value;

bytes:
  8a442404 3881c8000000 8881c7000000 7406 8881c8000000 c20400

call sites (patterns):
  push 0 / push 1 / push reg8-bool
  mov ecx, weapon*
  call 0x0056a260
```

**No conflict** among raw, force_decompile, and body bytes on sealed CF.

Sibling seal (not owned): `FUN_0056d520` body fragment:

```
*(u8*)(w+199) = 1;
if (*(u8*)(w+200) != 1) *(u8*)(w+200) = 1;
*(u8*)(w+0xC9) = 1;
```

≡ this helper with `value=1` **plus** `+0xC9`.

---

## 4. Surviving contract for AutoCore

```csharp
// Weapon_SetFireFlagPair_Inferred @ 0x0056a260
// this = hardpoint weapon* (vehicle+0x260[i], i=0..2)
// stack: u8 value; RET 4

void SetFireFlagPair(Weapon* w, byte value)
{
    // Instruction order: compare old +0xC8 first
    byte oldTwin = w->ByteC8;          // +0xC8
    w->ByteC7 = value;                 // +0xC7 always
    if (oldTwin != value)
        w->ByteC8 = value;             // +0xC8 only on change
}

// Related cluster (sibling-owned):
//   +0xC9 set to 1 by FUN_0056d520; often cleared after SetFireFlagPair(0)
//   +0xCB set by FUN_0056b400 (blocks start-fire when non-zero)
```

Port notes:

- **Do not** apply drive-axis `0xC7` mask logic here.
- Clearing fire for recovery/enter-world/input should call this with `0` (and usually clear `+0xC9` in the same caller).
- Start-fire may either call this with `1` or inline the pair + set `+0xC9` (`FUN_0056d520`).
- After return both bytes equal `value`; the change-gate only skips a redundant store to `+0xC8`.

---

## 5. Open questions

1. Why always rewrite `+0xC7` even when already equal (write side-effect / simpler code / observer)?
2. Product names for the three hardpoint classes sharing this layout.
3. Net pack bit that feeds UnpackGhostVehicle → this setter.
4. Exhaustive reader list for `+0xC7`/`+0xC8` (firing probes, ghost encode).
5. Runtime / package bit-exact.

**Verdict:** **accept-with-gaps** — adversarial attacks on entity-this, mask conflation, always-both-writes, stabilizer-only role, and three-rep drift **closed**; product English + consumers remain open.
