# Review B (skeptical / adversarial): `aa_0051f940` LookupClassDisplayName_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051f940` |
| **VA** | `0x0051f940` |
| **Canonical name** | `LookupClassDisplayName_Inferred` (**Inferred**) |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_0051f940_LookupClassDisplayName_Inferred.md` |
| **System** | missions-progression / character display |
| **Live tools** | Independent decompile + `read_memory` + caller decompiles |
| **Verdict** | **accept-with-gaps** — accept leaf table; reject 3-arg / race-first / ring-owning / character-thiscall claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Takes 3 args (wrapper decomp `…, 0xffffffff`) | **Falsified** — leaf uses only `[esp+4]`/`[esp+8]`; wrapper `add esp,8` |
| 2 | Arg order is (race, class) | **Falsified** — outer switch is first arg; families are Commando/Engineer/Officer/Ranger (class), not races |
| 3 | `__thiscall` / ECX character | **Falsified** — pure stack cdecl; no `this` loads |
| 4 | Owns TLS ring buffer | **Falsified** — returns static imm strings; ring is `007a69d0`/`007a6de0` in wrappers |
| 5 | Mutable / heap return | **Falsified** — `mov eax, imm32` of rodata |
| 6 | Contains race-only names (Human/Mutant/Biomek) | **Falsified** — those live in race helper; this is class archetypes |
| 7 | Product method name proven | **Rejected** — English table High; symbol Inferred |
| 8 | classId>3 crashes | **Falsified** — default returns `"Unknown"` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Leaf CF / table content | **Confirmed** | Wrong `[$class]` text |
| cdecl 2-arg ABI | **Confirmed** | Stack imbalance |
| Static return lifetime | **Confirmed** | Spurious free |
| Product symbol English | **None** | Overclaim |
| Race column meanings | **Peer** | Mislabel race×class matrix docs |

---

## 3. Decompiler pitfalls (must survive port)

1. Never invent a third arg from wrapper decomp paste.
2. Keep **(classId, raceId)** order.
3. Do not free the return pointer.
4. Port as pure function; do not pull ring buffer into this unit.
5. Preserve case-2/3 explicit race0 vs case-0/1 fold-to-base asymmetry.

---

## 4. What is safe to claim

| Safe | Unsafe |
|---|---|
| Full English class×race table as implemented | PDB / design-doc class names beyond strings |
| cdecl leaf used by `[$class]` wrapper | That race 0/1/2 labels without race dual |
| Static C-string return | Heap ownership / localization tables elsewhere |

---

## 5. CF challenge of Review A

- Table + ABI Confirmed: **agree**
- Inferred product method name: **agree**
- accept-with-gaps: **agree**

**Verdict:** **accept-with-gaps**
