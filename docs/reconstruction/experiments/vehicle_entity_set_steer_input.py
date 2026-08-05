"""
Exact-behavior pure model of VehicleEntity_SetSteerInput @ 0x004f5620
(autoassault.exe). For differential / unit tests of the reconstructed gate.

Does not modernize: no clamps, no extra validation. Mirrors reconstructed-exact.
"""

from __future__ import annotations

from dataclasses import dataclass
from typing import Optional

# Confirmed from decompile: decimal 199 == 0xC7 (write-suppress mask; not proven "lock")
INPUT_AXIS_SUPPRESS_MASK = 0xC7
# Back-compat alias used by older notes; prefer INPUT_AXIS_SUPPRESS_MASK
INPUT_AXIS_LOCK_MASK = INPUT_AXIS_SUPPRESS_MASK


@dataclass
class DriveAxisGateObject:
    """Unresolved retail type; only +0xB4 flags participate in this function."""

    flags_at_0xb4: int = 0


# Alias kept for existing tests / imports
DriveAxisLockObject = DriveAxisGateObject


@dataclass
class VehicleEntityDriveAxes:
    """Partial entity model: drive-axis fields used by the setters.

    Models the *gate decision* only. Does not execute the retail pointer chain
    (intermediate nulls on p0/p1 fault in retail; only final wobj null is checked).
    """

    longitudinal_input: float = 0.0  # +0x614
    steer_input: float = 0.0  # +0x618
    handbrake_flag: int = 0  # +0x61c
    lock_object: Optional[DriveAxisGateObject] = None  # resolved final wobj


def resolve_drive_axis_gate_object(
    entity: VehicleEntityDriveAxes,
) -> Optional[DriveAxisGateObject]:
    """
    Retail resolves:
      wobj = *( *(*(this+4)+4) + this + 0xB0 )
    This pure model assumes that chain already succeeded; entity.lock_object is wobj.
    """
    return entity.lock_object


def input_axis_write_allowed(gate_object: Optional[DriveAxisGateObject]) -> bool:
    """Gate shared by SetSteerInput and SetLongitudinalInput (suppress-if-bits)."""
    if gate_object is None:
        return True
    return (gate_object.flags_at_0xb4 & INPUT_AXIS_SUPPRESS_MASK) == 0


def vehicle_entity_set_steer_input(
    entity: VehicleEntityDriveAxes, steer_axis: float
) -> None:
    """
    void __thiscall VehicleEntity_SetSteerInput(VehicleEntity* this, float steerAxis)

    if (wobj == 0 || (flags & 0xC7) == 0)
        this->steerInput (+0x618) = steerAxis;

    Axis sign/magnitude is entirely caller-supplied; this function does not map keys.
    """
    wobj = resolve_drive_axis_gate_object(entity)
    if input_axis_write_allowed(wobj):
        entity.steer_input = steer_axis


def vehicle_entity_set_longitudinal_input(
    entity: VehicleEntityDriveAxes, longitudinal_axis: float
) -> None:
    """Sibling @ 0x004f5650 — same gate, store +0x614."""
    wobj = resolve_drive_axis_gate_object(entity)
    if input_axis_write_allowed(wobj):
        entity.longitudinal_input = longitudinal_axis
