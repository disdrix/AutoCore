# Review B (skeptical / adversarial): `aa_004bb950` Object_ResolveFromTFID

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bb950` |
| **VA** | `0x004bb950` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004bb950_Object_ResolveFromTFID.md` |
| **Evidence** | Adversarial re-read of raw + **image bytes** (`read_memory`); call-site ECX setups; callee dual `aa_004bae70` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Pure `__stdcall` free function (Ghidra sig) | **Falsified** | Callers always `MOV ECX, resolveCtx` before CALL; body preserves ECX into Resolve which **requires** ECX |
| 2 | Performs hash lookup / table select itself | **Falsified** | Body is push×3 + call + ret; dual-table logic is `0x004bae70` |
| 3 | Full 16-byte TFID copy into Resolve | **Falsified** | Only loads +0, +4, +8 |
| 4 | Null-safe on `pTfid` | **Falsified if claimed** | Immediate `[eax]` deref; null → fault |
| 5 | Mutates world / registers object | **Falsified** | No stores; pure resolve path |
| 6 | `bGlobal` push is clean zero-extended byte | **Over-strict** | `MOV AL` leaves residual upper bits; callee byte-cmp only |
| 7 | Scaffold decompile is ABI-complete | **Falsified** | Missing `this`/ECX entirely |
| 8 | Always returns non-null for valid TFID layout | **Falsified** | Callee: invalid sentinel, domain flags off, table miss → 0 |
| 9 | Server-only helper | **Falsified** | Massive client fan-in (Recv*, skills, UI, patrol, drive) |
| 10 | ECX source is always `+0xe4e8` | **Over-narrow** | Sites also use `+0xd34` and other hosts; **this unit** only requires “some ctx with Resolve layout” |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Unpack offsets +0/+4/+8 | **High** (image) | Wrong TFID layout → silent miss / wrong object |
| ECX passthrough ABI | **High** (call sites + callee uses ECX) | Port as free function → always null or crash |
| Sole callee `0x004bae70` | **Confirmed** | Mis-wire to wrong resolve |
| No local domain gates | **High** | Duplicating gates in wrapper would double-filter |
| ctx type / host offsets | **Tentative** | Wrong host field → wrong table |
| Clean zero-extend of bGlobal | **N/A behavioral** | Residual bits ignored by callee |

---

## 3. Cross-check spine (must match image)

```
// Object_ResolveFromTFID — OWN body only
ctx = ECX                    // caller-supplied; not loaded here
p   = [esp+4]
push dword [p+4]             // hi
push dword [p+0]             // lo
push (AL = byte [p+8])       // bGlobal low
call CVOGReaction_ResolveObjectTarget
ret 4
```

Scaffold raw decompile matched **field names** and **callee** but **not** thiscall. Strengthen clean must document `ctx` ECX.

Callee spine (not re-owned; must remain consistent):

```
if (lo & hi) == -1: return 0
if bGlobal != 0: gate ctx+0xc, table ctx+0x4
else:            gate ctx+0xd, table ctx+0x8
return HashLookup(table, lo, hi)  // object* or 0
```

---

## 4. Surviving contract for AutoCore

```
Object_ResolveFromTFID(ctx, pTfid) -> object*|null
  requires ctx with same dual tables/flags as ResolveObjectTarget
  unpacks TFID_16 head {lo@0, hi@4, global@8}
  no mutation; no null guard on pTfid
```

**Port traps to reject:**

- Implementing as free function with a hidden global ctx unless proven every caller’s ECX is that global.
- `memcpy` of full 16 B TFID into lookup key (pad not used).
- Inventing null → null early-out if matching retail fault-on-null.
- Inlining dual-table select **without** also matching `aa_004bae70` flag polarity.

---

## 5. Open questions

1. Product type of `ctx` and whether `+0xe4e8` vs `+0xd34` always alias the same resolve manager.
2. Runtime frequency of null returns vs faults on bad pointers.
3. Diff / bit-exact vs retail image.
4. Whether Ghidra plate name is PDB-backed or analyst-assigned (behavior independent).

**Verdict:** **accept-with-gaps**. Trust **bytes + call-site ECX**, not Ghidra’s stdcall-only signature. Residual: ctx product typing and runtime/diff.
