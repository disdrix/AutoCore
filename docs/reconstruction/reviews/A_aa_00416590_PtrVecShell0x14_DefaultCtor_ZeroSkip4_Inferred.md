# Review A (reconstruction fidelity): `aa_00416590` PtrVecShell0x14_DefaultCtor_ZeroSkip4_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416590` |
| **VA** | `0x00416590` |
| **Canonical name** | `PtrVecShell0x14_DefaultCtor_ZeroSkip4_Inferred` |
| **Ghidra name** | `FUN_00416590` |
| **Prior scaffold** | `FUN_00416590` partial trio |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_00416590_PtrVecShell0x14_DefaultCtor_ZeroSkip4_Inferred.md` |
| **System** | util / container shell (elem **0x14**) |
| **Wave** | WQ9I-J OWN |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Default constructor for a 0x14-byte pointer-vector shell**:

```text
// ECX = shell*
// zero +0, +8, +0xC, +0x10
// leave +4 untouched
// ret 0 (leaf)
```

Used as:

- `_eh_vector_constructor_iterator_` element ctor (size **0x14**, count **9**, dtor `FUN_00417ee0`) inside `FUN_00820830` (audio UI host+0xEE4).
- Static BSS default-init for four shells at `0xd218e0 + n*0x14` then `_atexit`.

**Not** related to neighbor scalar dtor `004165f0` beyond VA neighborhood.

---

## 2. ABI (SEALED)

| Slot | Role |
|---|---|
| **ECX** | `Elem0x14*` this |
| stack | none |
| return | void; **`ret 0`** (`C3`) |

---

## 3. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` / `analyze_function_complete` @ `0x00416590` ≡ raw CF |
| Bytes | `read_memory` 63 B — SEH + four zero stores; no `[EAX+4]` write; `C3` |
| Callers | xrefs + `get_assembly_context` @ eh_vector push + four BSS CALL sites |
| Callees | none |
| Peer dtor | `FUN_00417ee0` live decompile (evidence only) |
| Raw / annotated / clean | `aa_00416590_*`, named plate |

**Not performed:** Launcher, runtime, ledgers, `disassemble_bytes`.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH install `LAB_009bcfab` | **Yes** (bytes; decompiler elides) |
| Zero +0/+8/+0xC/+0x10 | **Yes** |
| Skip +4 | **Yes** (no store in hex) |
| `ret 0` | **Yes** (`C3`) |
| Invented branches | **None** |

### Recovered CF

```c
void __thiscall Ctor(uint32_t* self /*ECX*/)
{
  self[0] = 0;
  self[2] = 0;
  self[3] = 0;
  self[4] = 0;
}
```

---

## 5. Gaps

- Product English for shell / fields +0 and +4.
- Why +4 is not zeroed (UB risk off BSS vs intentional).
- Peer dtor / static complete dtor not dual-owned.
- Runtime / bit-exact / differential.

---

## 6. Verdict

**accept-with-gaps** — CF/ABI/elem-size/zero-skip sealed from bytes + call sites. Product demangle and +4 rationale residual. Not reject.
